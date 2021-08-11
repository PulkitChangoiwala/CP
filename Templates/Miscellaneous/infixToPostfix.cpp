class Evaluate {
    int ans;
    string infix; //infix expression should not contain unary operators
    string postfix;
public:
    Evaluate(string expression, int type){
        ans = 0;
        if(type==0){
            this->infix = "(" + expression + ")";
            infixToPostfix();    
        }
        else {
            postfix = expression;           
        }
        evaluatePostfix();
        
    }
    
    bool isOp(char ch){
        return ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^';
    }
    int preced(char ch) {
        if(ch == '+' || ch == '-') { return 1; }
        else if(ch == '*' || ch == '/') { return 2;}
        else if(ch == '^') { return 3;}
        else { return 0;}
    }
    
    int operate(int num2, int num1, char ch){
        switch(ch){
            case '+' : num1 = num2 + num1; break;
            case '-' : num1 = num2 - num1; break;
            case '*' : num1 = num2 * num1; break;
            case '/' : num1 = num2 / num1; break;
            case '^' : num1 = num2 ^ num1; break;

        }
        return num1;
    }
    
    void infixToPostfix(){
        postfix = "";
        string num = "";
        stack<char> st;
        st.push('#');
        for(auto ch : infix){
            if(isalnum(ch)) num += ch;
            else {
                if(num.length()) {
                    postfix += '_'+num+'_';
                    num = "";
                }
                
                if(ch == '(') st.push('(');
                else if(ch == ')') {
                    while(st.top()!='#' && st.top()!='('){
                        postfix += st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else if(isOp(ch)) {
                    if(preced(ch) > preced(st.top())) st.push(ch);
                    else {
                        while(st.top()!='#' && preced(ch) <= preced(st.top())) {
                            postfix += st.top();
                            st.pop();
                        }
                        st.push(ch);
                    }
                }
            }
        }
        
        
        while(st.top()!='#') {
            postfix += st.top();
            st.pop();
        }
    }
    
    
    
    
    void evaluatePostfix(){
        
        string num = "";
        stack<int> st;
        for(auto ch : postfix){
            if(isdigit(ch)) num += ch;
            else if(ch == '_' && num.length()) {st.push(stoi(num)); num = "";}
            else if(ch!='_'){
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                
                
                num1 = operate(num2, num1, ch);
                st.push(num1);
            }
        }
        ans = st.top();
        st.pop();
    }
    
    
    int getValue(){
        return ans;
    }
    
    void print(){
        cout<<postfix<<endl;
    }
    
  
};

