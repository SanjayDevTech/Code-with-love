// Impelemented an optimized extension of linear search.

function TwoWayLinearSearch(list=[],number=""){
    if(Array.length==0) return false
    if(number=="") return false
    for(var i=0,j=list.length-1;i<=parseInt(list.length)+list.length%2;i++,j--){
        if(list[i]==number){
            return true
        }
        if(list[j]==number){
            return true
        }
    }
    return false
}

//[,3,4,5,-1,6,7,8]
TwoWayLinearSearch([,3,4,5,-1,6,7,8],-1)
//true