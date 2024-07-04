class Node{
    constructor(data , next = null){
        this.data = data;
        this.next = next;
    }
}

class SinglyLinkedList {
    constructor(head = null){
        this.head = head;
        this.size = 0;
    }

    // insert first
    insertFirst(data){
        let newNode = new Node(data);
        newNode.next = this.head;
        this.head = newNode;
        this.size++;
    }

    // insert between
    insertBetween(data , index){
        let newNode = new Node(data);
        let temp = this.head;
        let i =0;
        while(i !=index-1){
            temp = temp.next;
            i++;
        }

        newNode.next = temp.next;
        temp.next = newNode;
        this.size++;
    }

    // insert end
    insertEnd(data){
        let newNode = new Node(data);

        if(!this.head){
            this.head = newNode;
            return;
        }

        let last = this.head;

        while(last.next){
            last = last.next;
        }
        last.next = newNode;
        this.size++;
    }

    // get size
    getSize(){
        return "Size: \t" + this.size;
    }

    // clear
    clear(){
        this.head = null;
    }

    // print list
    printList(){
        let temp = this.head;
        console.log("Traversing Singly LL");
        while(temp){
            console.log("Element : " + temp.data);
            temp = temp.next;
        }
    }

    // sum 
    sumNodes(){
        let sum = 0;
        let temp = this.head;
        while(temp){
            sum += temp.data;
            temp = temp.next;
        }
        return "Sum : \t" + sum;
    }

    // get first
    getFirst(){
        return this.head.data;
    }

    // get last
    getLast(){
        let last = this.head;

        while(last.next){
            last = last.next;
        }

        return last;
    }
}



let sl1 = new SinglyLinkedList();
sl1.insertFirst(10);
sl1.insertFirst(11);
sl1.insertFirst(12);
sl1.insertBetween(2 , 2);
sl1.insertEnd(20);

sl1.printList();

console.log(sl1.getSize());

console.log(sl1.sumNodes());

console.log(sl1.getFirst());

console.log(sl1.getLast());


sl1.clear();