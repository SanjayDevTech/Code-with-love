
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class LinkList {
    constructor() {
        this.head = null;
    }

    /**
     * 
     * @param {*} data data need to be inserted in the linkList. 
     */
    insertNodeAtBeginning(data) {
        let node = new Node(data);
        if(this.head == null) {
            this.head = node;
        } else {
            let temp =  this.head;
            this.head = node;
            node.next = temp;
        }
    }

    /**
     * 
     * @param {*} data data need to be inserted in the linkList. 
     */
     insertNodeAtEnd(data) {
        let node = new Node(data);
        if(this.head == null) {
            this.head = node;
        } else {
            let temp =  this.head;
            while(temp.next != null) {
                temp = temp.next;
            }
            temp.next = node;
        }
    }

    /**
     * 
     * @param {*} data adding node after this data
     * @param {*} newData add newData node.
     */
    insertAfterNode(data, newData) {
        let node = this.search(data);
        if(node == null) {
            return `${data} not found in the list.`;
        }
        let newNode = new Node(newData);
        newNode.next = node.next;
        node.next = newNode;
        return 'Node inserted successfully.'
    }

    /**
     * 
     * @param {*} node node from which you want to print the node.
     */
    print(node) {
        let temp = node;
        while(temp != null) {
            console.log(temp.data);
            temp = temp.next;
        }
    }

    /**
     * function for getting the head of the linkList.
     */
    getHead() {
        return this.head;
    }
    
    search(data) {
        if(this.head == null) {
            return null;
        }
        let temp = this.head;
        while(temp != null) {
            if(temp.data == data) {
                return temp;
            }
            temp = temp.next;
        }
        return null;
    }
}

let LT = new LinkList();

console.log('Linked List Head Value =>', LT.getHead());

LT.insertNodeAtBeginning(4);
LT.insertNodeAtBeginning(5);
LT.insertNodeAtBeginning(3);
LT.insertNodeAtEnd(10);
LT.insertNodeAtBeginning(1);

console.log('Linked List after node entries =>');
LT.print(LT.getHead());

console.log('Linked List Head Value =>', LT.getHead());

console.log('Search 3', LT.search(3))

console.log('Insert node 19 value after 3 =>', LT.insertAfterNode(3,19));

console.log('Linked List values =>');
LT.print(LT.getHead())