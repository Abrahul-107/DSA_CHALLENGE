package java_linkedlist;

class Node
{
    int data;
    Node right;
    Node left;
    public Node(int data)
    {
        this.data = data;
        this.left = null;
        this.right = null;
    }


}

public class BasicOperationsLinkedlist
{
    public static Node insertNode(Node head,int value)
    {
        Node newNode = new Node(value);
        if(head==null)
            return newNode;
        Node temp = head;
        while(temp.right!=null)
            temp = temp.right;
        temp.right = newNode;
        return head;
    }
    public static Node insertNodeAtHead(Node head,int value)
    {
        Node newNode = new Node(value);
        newNode.right = head;
        head = newNode;

        return head;
    }
    public static Node insertNodeAtSpecificPosition(Node head,int val,int position)
    {
        Node curr = head;
        Node addNode = new Node(val);
        int c = 0;
        while (curr!=null && c<position-1) 
        {
            curr = curr.right;
            c++;
        }
        if(curr==null)
            System.out.println("position not found");
        addNode.right = curr.right;
        curr.right = addNode;
        addNode.left = curr;

        return head;
    }
    public static void traverse(Node head) 
    {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.right;
        }
        System.out.println();
    }
    public static void main(String[] args) 
    {
        Node head = null;

        // Insert nodes into the linked list
        head = insertNode(head, 10);
        head = insertNode(head, 20);
        head = insertNode(head, 30);
        head = insertNodeAtHead(head, 5);
        traverse(head);
        head = insertNodeAtSpecificPosition(head, 25, 1);

        // Traverse and print the linked list
        System.out.println("Linked List:");
        traverse(head);

        
    }
    
}


