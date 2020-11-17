function reverseString(st){
    
    var revStr = "";
    var i=0;
    for(i=st.length-1;i>=0;i--){
        revStr += st[i];
    }    
    return revStr;
}

reverseString('hello');
