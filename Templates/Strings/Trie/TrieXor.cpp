struct TrieNode{
    int count;
    int end;
    vector<TrieNode*> next;
    TrieNode(int count = 0){
        this->end   = 0;
        this->count = count;
        this->next.resize(2, nullptr);
    }
};
class TrieXor{
    #define bits 18
    TrieNode *root;
    
public:
    TrieXor(){
        this->root = new TrieNode;
    }
    
    void insert(int num){

        // bitset<bits> bin(num); //binary representation
        int bit = 0;
        TrieNode*curr = root;
        for(int i=bits-1; i>=0; --i){ //filling MSB to LSB
            bit = (num&(1<<i))!=0;
            curr->count++;
            if(!curr->next[bit]) 
                curr->next[bit] = new TrieNode;
            curr = curr->next[bit];
        }
        curr->count++;
        curr->end++; //counting how many prefixes ends at this position
    }
    
    void erase(int num){ //removing num from trie
        //ideally we should use delete operator, but delete operator is time costly
        //so we are using this work around
        int bit = 0;
        TrieNode*curr = root;
        curr->count--;
        for(int i=bits-1; i>=0; --i){
            bit = (num&(1<<i))!=0;
            curr->next[bit]->count--;
            if(i==0) curr->next[bit]->end--;
            if(curr->next[bit]->count == 0){
                curr->next[bit] = nullptr;
                break;
            }
            curr = curr->next[bit]; 
        }
    }
    
    
    bool search(int num){
        int bit = 0;
        TrieNode*curr = root;
        for(int i=bits-1; i>=0; --i){
            bit = (num&(1<<i))!=0;
            if(!curr->next[bit]){
                return false;
            }
            curr = curr->next[bit];
        }
        return true;
    }
    
    int maxXor(int num){ //returns the value having max xor with val

        int res = 0, bit = 0;
        TrieNode*curr = root;
        for(int i=bits-1; i>=0; --i){
            bit = (num&(1<<i))!=0;
            if(!curr->next[bit^1]) 
                curr = curr->next[bit];
            else {
                res |= (1<<i);
                curr = curr->next[bit^1];
            }
        }        
        return res;
    }
};