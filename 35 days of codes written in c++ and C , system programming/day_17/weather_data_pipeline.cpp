#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <chrono>
#include<condition_variable>
#include <string>
#include <filesystem>
#include<cstring>
using namespace std;

static mutex mt;

static mutex cout_mtx; 
int count = 0 ; 
condition_variable cv; 




struct weather{
      char  city[50] ;
      float temp; 
      float minTemp; 
      float maxTemp; 
     float  rainpct; 
    weather * next ; 
   
};

weather* start ,*ptr = nullptr  ; 


void generate_thread( int timeout ) {
           
         while(true){

         this_thread::sleep_for(chrono::seconds(timeout));

          unique_lock<mutex> lock (mt) ;

         weather* newnode = new weather; 

         
         strcpy(newnode->city, "city" ) ;

         newnode->temp = ( rand()%100 ) ;
            newnode->minTemp = ( rand()%100 ) ;
            newnode->maxTemp = ( rand()%100 ) ;
           newnode->rainpct = ( rand()%100 ) ;
              

          newnode->next = nullptr; 

        if(start==nullptr){
             start =newnode ; 
             ptr = newnode; 
        }  
           else {
                 ptr->next = newnode ; 
                  ptr = newnode ; 
                }
             count++; 
          
          if(count>=30){
             cv.notify_all(); 
	     cv.wait(lock ,[] { return count==0; });
           }
      }   
} 



void writer_thread(const string& filename)
{
             while(true) {

             unique_lock<mutex> lock (mt) ;
             cv.wait(lock ,[]{ return count>=30; }); 

            
     
       ofstream out(filename, ios::out | ios::app);
             if (!out)
    {
        lock_guard<mutex> lk(cout_mtx);
        cerr << "[Writer] ERROR: cannot open file for writing.\n";
        return;
    }
         
         weather * current = start ; 
        
         while(current != nullptr) {
             out << current->city<< " " << current->temp<< " " << current->minTemp << " " << current->maxTemp << " " << current->rainpct << "\n";
            
              weather *temp1 = current ; 
           current = current->next; 
             delete temp1; 
            
           }  
            out.flush();
            out.close(); 
          
           current  = nullptr; 
           start = nullptr ; 
            count = 0; 
         
          cout<< "data is written: "<<"\n";
          
       
      }

    
}


// Reader thread: waits for file, then reads new lines as they arrive (tail-like)
void reader_thread(const string& filename, int poll_ms, int timeout)

 {
       while(true) {

           this_thread::sleep_for(chrono::seconds(timeout));

            lock_guard<mutex> lock2 (mt);
         
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

           string line;
        int idle_ms = 0;
        
           while(true){
           if(getline(in,line)){ 
              lock_guard<mutex> lk(cout_mtx);

               cout<<line<<endl ;  

          }
               else {
 
            // No new line available yet.

            // Clear EOF and keep waiting for more data.
            in.clear();
 
            this_thread::sleep_for(chrono::milliseconds(poll_ms));
            idle_ms += poll_ms;
 
            // If no new data for a while, exit (prevents infinite looping).
            if (idle_ms >= timeout)
            {
                lock_guard<mutex> lk(cout_mtx);
                cout << "[Reader] No new data for " << timeout << " ms. Exiting.\n";
                break;
            }

           in.close(); 

}
}
      }        
}



 
 
int main()
{
    const string filename = "thread_io_log.txt";
 
    // (Optional) start fresh each run by truncating the file:
    {
        ofstream clear_file(filename, ios::out | ios::trunc);
    }
 
      thread t1(generate_thread, 1);

       thread t_writer(writer_thread, filename);
    
    
    // Start reader first (it will wait for file, then read as writer appends)
    thread t_reader(reader_thread, filename,
                    /*poll_ms=*/100,
                    /*idle_timeout_ms=*/60);
 
    
    t1.join();
    t_writer.join();
    t_reader.join();
 
    cout << "Main: Done. Check file: " << filename << "\n";
    return 0;
}
