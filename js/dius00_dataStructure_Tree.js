 // Javascript ES6 syntax code sample for Tree (non-binary) data structure

/* 
* Creates the Tree
* if a value is given to the constructor
* the element will be initialized as an instance of Tree
*/
class Tree {
  constructor(value) {
    if(value !== undefined){
      this.value = value;
      this.children = [];
    }
  }
  
/* 
* Method to add a new child to the Tree
*/
  addChild(value) {
    const newTree = new Tree(value); // Generates a new Tree element
    this.children.push(newTree);     // Adds the newTree (child) to the children Array
    return newTree;                  // Returns the new Tree
  }

/* 
* Method to check if a value exists in the tree
*/
  contains(value) {
    // initializes the result as false
    let result = false;           

    /* 
    * declare a searchValue function that travels recursivly
    * through the Tree and his Childre  
    */  
     function searchValue(tree) {    
      // if the current Tree value is equal to the one we are looking for
      // change the result to true
      if (tree.value === value) result = true;
      // if the Tree has children
      if (tree.children !== []) {
        // for each of them call an instance of the searchValue function
        for (const child of tree.children) searchValue(child);
      }
    }
    // call the searchValue function on or parent Tree
    searchValue(this);

    // returns the result
    return result;
  }

  /* 
  * Method to remove a Tree if it has a certain value
  */
  remove(value) {
    let removedValue;
    function searchValue(tree) {
      let childHasValue = false;
      if (tree.children !== []) {
        for (const child of tree.children) {
          if (child.value === value) {
            childHasValue = true;
            removedValue = child;
          }
          if (childHasValue) {
            tree.children.splice(tree.children.indexOf(removedValue), 1);
          } else {
            for (const child of tree.children) searchValue(child);
          }
        }
      }
    }
    searchValue(this);
    // returns the removed value
    return removedValue;
  }