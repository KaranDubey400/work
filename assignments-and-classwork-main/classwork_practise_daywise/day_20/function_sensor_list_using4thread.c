/* problem statement
  function that will create N sensor nodes based on the number passed to it
   compute average , mean for each sensors . add a new sensor dynamically
   Function to free the nodes that are created 
   delete all sensor nodes and samples before program termination (non-threaded).
   delete a specific sensor and its samples using sensor ID (threaded).
   arrays are not allowed; only linked lists must be used.
   */
    
typedef struct sensor {
 int sensorId    // for each sensor node 
 int sampleCount   // total samples for each sensor node
 int *samples      // pointer to samples for each sensor node
 sensor *next      // pointer to next sensor node
 }
 
 algorith---
 
 step1: main() - create sensor nodes with specified number
 step2: allocate samples and insert into the list 
 step3: create a function to compute average and mean for each sensor and print it to console(mean & average)
 step4: create a function to delete specific sensor
 step5: create a function to delete all the nodes
 step6: wait for all thread to complete their execution
 step7: exit
 
 functions--
 
 1. generate n nodes ( non threaded)
 2. calculate average  (threaded)
 3. delete specific node (threaded)
 4. delete all nodes (non threaded)
 5. add node (threaded)


pseudo code--

include all the header files
STRUCT Sample
    int value
    Sample* next
END STRUCT

STRUCT Sensor
    int sensorId
    int sampleCount
    Sample* sampleHead
    Sensor* next
END STRUCT

    
    struct* start , current = nullptr
    
    function ( create sensor node)
            
              loop (0 to n){
              create a new sensor node
              assign sensorId = i
              assign sample_count = 5
                initial sample *head
                loop( 0 to 5 ){
                 assign sample value 
                   head->next
                 } 
                 attach sensor node
            
        end function 
        
   
   thread function (compute average)
            lock
            sensor temp = start 
            while loop ( temp ){
            int sum = 0 
            sample temp= samples 
            while loop (sample temp){
             sum += *sample temp
               sample temp = sample->next
             }
            double avarage = (double)sum/ temp->sample count ;
            print(id, average)
            temp = temp->next
            }
            unlock 
      end function
      
      
      
      thread function (delete specific sensor, id)
      lock
         sensor temp = head
          *prev = null 
          while(temp && temp->sensor_id != id ){
            prev = temp
            temp =temp->next
            }
            if(temp == null ){
            prev->next = null
            }
            
            else{
            prev->next = temp->next 
            }
            
            delete samples list in temp
            delete temp
            unlock
            print message sensor delete of id
            
        end function
        
     
     FUNCTION deleteallsensors
        tempSensor = head

      WHILE tempSensor != NULL
        delete sample list
        delete sensor node
        tempSensor = next
    END WHILE

         head = NULL
        END FUNCTION

            
            
            
                  
              
            
    
    begin main() 
         set n
         createSensors(n)
        create thread t1 ( compute average )
        create thread t2 (delete specific sensor)
        create thread t3 (add node)
         join all thread
         delete all nodes
    end main
  
   

    WHILE true
        display menu
        read choice

        IF choice == 1
            create thread computeAverage
            join thread

        ELSE IF choice == 2
            read sensorId
            create thread deleteSensor
            join thread

        ELSE IF choice == 3
            create thread addSensor
            join thread

        ELSE IF choice == 4
            break
    END WHILE

    deleteAllSensors
    destroy mutex
END MAIN

    
    
        
    
    
 
 
 
 
 
