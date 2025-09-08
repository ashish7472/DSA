stack<int> sortStack(stack<int>& st){

    stack<int> tempstack; //in the end isme sorted order hoga elements ka like 5,4,3,2 ...

    while(!st.empty()){
        int temp = st.top();
        st.pop();

        //push all the elements from tempstack if they are > the st.top()
        while(!tempstack.empty() && tempstack.top() > temp){
            st.push(tempstack.top());
            tempstack.pop();
        }

        tempstack.push(temp);
    }

    return tempstack;
}