// Javascript ES6 syntax code sample for Doubly-Linked List


/* 
* Creates the Doubly-Linked List
* if a value is given to the constructor
* the element will be initialized as a Node (below)
*/
class DoublyLinkedList { 
  constructor(value){
      if(value !== undefined){
      this.head = new Node(value);
      this.tail = this.head;
      }
  }

/* 
* Method to add a new Node to the list
*/
  addNode(value){
      const newNode = new Node (value);  // Generates a new Node element
      if(!this.head) {                   // if there is no head make the new Node the head of the list
          this.head = newNode
      } else {                           // if there is a head, link the new Node to the tail of the list
      this.tail.next = newNode;
      newNode.prev = this.tail;
      this.tail = newNode;
    }
  }

/* 
* Method to remove the head
*/

  removeHead() {
    const oldHead = this.head;
    this.head = this.head.next;
    return oldHead;
  }

/* 
* Method to find a specific Node in the list
*/

  findNode(value) {
    let iterator = this.head;
    while (iterator) {
      if (iterator.value === value) return iterator;
      iterator = iterator.next;
    }
    return null;
  }
}


/* 
* Method to find a specific Node in the list
*/

class Node {                          
  constructor(value){
      this.value = value;
      this.next = null;
      this.prev = null;
  }
}

// if you want to export this Class
// module.exports = DoublyLinkedList;
