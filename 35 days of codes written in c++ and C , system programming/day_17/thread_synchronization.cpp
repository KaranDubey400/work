#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>
#include <filesystem>
 
using namespace std;
 
static mutex cout_mtx;
 
// Writer thread: writes N lines with delays (appends)
void writer_thread(const string& filename, int lines, int delay_ms)
{
    {
        lock_guard<mutex> lk(cout_mtx);
        cout << "[Writer] Starting. Writing to: " << filename << "\n";
    }
 
    // Open in append mode so repeated runs don’t overwrite unless you want that behavior.
    ofstream out(filename, ios::out | ios::app);
    if (!out)
    {
        lock_guard<mutex> lk(cout_mtx);
        cerr << "[Writer] ERROR: cannot open file for writing.\n";
        return;
    }
 
    for (int i = 1; i <= lines; ++i)
    {
        string msg = "Line " + to_string(i) + " from writer thread";
        out << msg << "\n";
        out.flush(); // important so reader can see it immediately
 
        {
            lock_guard<mutex> lk(cout_mtx);
            cout << "[Writer] Wrote: " << msg << "\n";
        }
 
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
 
    {
        lock_guard<mutex> lk(cout_mtx);
        cout << "[Writer] Done.\n";
    }
}
 
// Reader thread: waits for file, then reads new lines as they arrive (tail-like)
void reader_thread(const string& filename, int poll_ms, int idle_timeout_ms)
{
    {
        lock_guard<mutex> lk(cout_mtx);
        cout << "[Reader] Starting. Waiting for file: " << filename << "\n";
    }
 
    // Wait until file exists
    while (!std::filesystem::exists(filename))
    {
        this_thread::sleep_for(chrono::milliseconds(poll_ms));
    }
 
    ifstream in(filename);
    if (!in)
    {
        lock_guard<mutex> lk(cout_mtx);
        cerr << "[Reader] ERROR: cannot open file for reading.\n";
        return;
    }
 
    // Optional: start from beginning. If you want "read only new lines", seek to end:
    // in.seekg(0, ios::end);
 
    string line;
    int idle_ms = 0;
 
    {
        lock_guard<mutex> lk(cout_mtx);
        cout << "[Reader] File opened. Reading...\n";
    }
 
    while (true)
    {
        // Try to read a line
        if (std::getline(in, line))
        {
            idle_ms = 0;
            lock_guard<mutex> lk(cout_mtx);
            cout << "[Reader] Read:  " << line << "\n";
        }
        else
        {
            // No new line available yet.
            // Clear EOF and keep waiting for more data.
            in.clear();
 
            this_thread::sleep_for(chrono::milliseconds(poll_ms));
            idle_ms += poll_ms;
 
            // If no new data for a while, exit (prevents infinite looping).
            if (idle_ms >= idle_timeout_ms)
            {
                lock_guard<mutex> lk(cout_mtx);
                cout << "[Reader] No new data for " << idle_timeout_ms
<< " ms. Exiting.\n";
                break;
            }
        }
    }
 
    in.close();
}
 
int main()
{
    const string filename = "thread_io_log.txt";
 
    // (Optional) start fresh each run by truncating the file:
    {
        ofstream clear_file(filename, ios::out | ios::trunc);
    }
 
    // Start reader first (it will wait for file, then read as writer appends)
    thread t_reader(reader_thread, filename,
                    /*poll_ms=*/100,
                    /*idle_timeout_ms=*/2000);
 
    // Start writer
    thread t_writer(writer_thread, filename,
                    /*lines=*/10,
                    /*delay_ms=*/200);
 
    t_writer.join();
    t_reader.join();
 
    cout << "Main: Done. Check file: " << filename << "\n";
    return 0;
}