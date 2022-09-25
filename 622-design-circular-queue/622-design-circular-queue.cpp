class MyCircularQueue {
    
private:
    
    vector < int > vec;
    int start = 0, len = 0;
    
public:
    
    MyCircularQueue( int k ){
        
        vec.resize(k);
        
    }
    
    bool enQueue( int value ) {
        
        if ( isFull() ) return false;
        
        vec[ ( start + len ) % vec.size() ] = value;
        
        len += 1;
        
        return true;
        
    }
    
    bool deQueue() {
        
        if ( isEmpty() ) {
            
            return false;
            
        }
        
        start = (start + 1) % vec.size();
        
        len -= 1;
        
        return true;
        
    }
    
    int Front() {
        
        if ( isEmpty() ) {
            
            return -1;
            
        }
        
        return vec[start];
        
    }
    
    int Rear() {
        
        if ( isEmpty() ) {
            
            return -1;
            
        }
        
        return vec[ ( start + len - 1 ) % vec.size() ];
        
    }
    
    bool isEmpty() {
        
        return len == 0;
        
    }
    
    bool isFull() {
        
        return len == vec.size();
        
    }
    
};