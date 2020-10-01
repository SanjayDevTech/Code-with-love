class Node{
    constructor(name){
        this.name=name;
        this.childre=[];
    }

    addChild(name){
        this.children.push(new Node(name));
        return this;
    }

    // O(v+e) time | O(v) space
    breadthFirstSearch(array){
        const queue=[this];
        while(queue.lenght>0){
            const current = queue.shift();
            array.push(current.children);
            for(const child of current.children){
                queue.push(child);
            }
        }
        return array;
    }
}
exports.Node = Node;