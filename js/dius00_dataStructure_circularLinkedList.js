// Javascript ES6 syntax code sample for Circular Linked List


/* 
* Creates the Linked List
* if a value is given to the constructor
* the element will be initialized as a Node (below)
*/
class CircularLinkedList {
  constructor(value){
      if(value !== undefined){
      this.sentinel = new Node(value); // a "sentinel" node has to be set in order control Read/Write operation
      }
  }
/* 
* Method to add a new Node to the list
*/
  addNode(value){
      const newNode = new Node(value);  // Generates a new Node element
      if(!this.sentinel) {              // if there is no head make the new Node the head of the list
          this.sentinel = newNode;
          this.sentinel.next = newNode;
          this.sentinel.prev = newNode;
          return;
      } else {                          // if there is a head, link the new Node to the tail of the list
      newNode.next = this.sentinel;
      newNode.prev = this.sentinel.prev.prev;
      this.sentinel.prev.next = newNode;
      this.sentinel.prev = newNode;
    }
  }

/* 
* Method to find a specific Node in the list
*/

 findNode(value) {
   if(this.sentinel){
      let iterator = this.sentinel;
      while(true) {
        if (iterator.value === value) return iterator;
        iterator = iterator.next;
        if(iterator === this.sentinel) break;
      }
    }
      return null;
    }
}

class Node {
  constructor(value){
      this.value = value;
      this.next = null;
      this.prev = null;
  }
}
