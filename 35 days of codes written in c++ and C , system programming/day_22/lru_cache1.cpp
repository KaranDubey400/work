#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <mutex>
#include <thread>
#include <vector>
#include <sstream>
using namespace std; 


struct Node {
    string key;
    string value;
    Node* prev;
    Node* next;

    Node(string k, string val) 
    {
        this->key = k;
        this->value = val;    
        prev = nullptr;
        next = nullptr;
    } 
};

class lru_cache {
       
    private:

    int capacity;

    unordered_map<string, Node*> cachemp;

    Node* head;

    Node* tail;

    recursive_mutex mtx;

    string persistencefile;

   
    void removenode(Node* node) {

        if (node->prev) {
            node->prev->next = node->next;
        } 
        else 
        {
            head = node->next;
        }

        if (node->next) {
            node->next->prev = node->prev;
        } 
        
        else {
            tail = node->prev;
        }

    }

    
    void addtohead(Node* node) {
        node->next = head;
        node->prev = nullptr;

        if (head) 
        {
            head->prev = node;
        }
        head = node;

        if (!tail)
         {
            tail = head;
        }

    }

    // shifting  existing node to  head (most recently used)
    void movetohead(Node* node) 
    {
        removenode(node);
        addtohead(node);
    }

    
    string readFile(const string& filename) {

         ifstream file;
        file.open(filename);

        if (!file.is_open()) {
            return "error file is not there";   // if not return error string
        }

        stringstream buffer;
        buffer << file.rdbuf();   // raw buffer read  , copy all file content to buffer
        file.close();
        return buffer.str();  // return file content as string
    }



    void statesave() {

        lock_guard<recursive_mutex> lock(mtx);

        cout << "saving cache state to " << persistencefile << " " << endl;
        
        ofstream outFile;
        outFile.open(persistencefile);
          
        if (!outFile.is_open()) {
            std::cerr << " error could not open " << persistencefile << " for writing" << endl;
            return;
        }

    
        Node* curr = tail;
        while (curr) {
            outFile << curr->key << "\n";  curr = curr->prev;
        }

        outFile.close();
        cout << "saved " << cachemp.size() << " keys" << endl;
    }


   
    void stateload() {
        cout << "loading cache state from " << persistencefile << " " << endl;

        ifstream inFile(persistencefile);

        if (!inFile.is_open()) {
            
            cout << " no existing state found. starting fresh" << endl;

            return;
        }

        string key;

        while (getline(inFile, key)) {

            if (!key.empty()) {
                
                cout << "warming key " << key << endl; 
                get(key); 

            }
        }

        inFile.close();

        cout << "cache warmed up" << endl;
    }

    
    public:

    lru_cache(int cap , string persisfile) 
     {
    this->capacity = cap;
    this->head = nullptr;
    this->tail = nullptr;
    this->persistencefile = persisfile;
    stateload();
    }

    ~lru_cache() {

        statesave();

        Node* current = head;

        while (current) {
            Node* next = current->next;

            delete current;

            current = next;
        }
    }

    string get(string key) {
        
        lock_guard<recursive_mutex> lock(mtx);

        if (cachemp.find(key) != cachemp.end()) {
        
            Node* node = cachemp[key];
            movetohead(node);

            cout << "[hit] key: " << key << " accessing from cache" << endl;

            return node->value;

        }
           else {
            

            string content = readFile(key);

            if (content == "error file is not there") {

                cout << "[error] key: " << key << " file not found." << endl;

                return content;

            }

            cout << "[miss] Key: " << key << " loading from disk/locally." << std::endl;

            Node* nwnode = new Node(key, content);

            if (cachemp.size() >= capacity) {
                //rm leacst recnt used item
                cout << "[evict] capacity full. temoving key: " << tail->key << endl;

                cachemp.erase(tail->key);
                Node* temp = tail;

                removenode(tail);

                delete temp;

            }

            addtohead(nwnode);

            cachemp[key] = nwnode;

            return content;
        }
    }
};


void worker(lru_cache &cache, int id, const vector<string>& files) {

    for (const auto& file : files) {
        

        this_thread::sleep_for(chrono::milliseconds(rand() % 100));

        string content = cache.get(file);
        
        
        static mutex printmt;
        {
            lock_guard<mutex> lock(printmt);

            cout << "thread " << id << " read " << file << " " << content.substr(0, 20) << " "  << endl;

        }
    }
}

int main() {

    string statefile = "cstate.txt";
   
    lru_cache cache(3, statefile); 

    vector<string> files = {
        "file1.txt", "file2.txt", "file3.txt", "file4.txt",
        "file1.txt", "file3.txt", "file2.txt , file5.txt"
    };


    thread   red (worker, ref(cache), 0, files);
    thread blue(worker, ref(cache), 1, files);
    thread green(worker, ref(cache), 2, files);
    thread black(worker, ref(cache), 3, files);

    red.join();
    blue.join();
    green.join();
    black.join();

    return 0;
}
