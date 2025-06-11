package java_linkedlist;

class Node
{
    int data;
    Node next;
    public Node(int data)
    {
        this.data = data;
        this.next = null;
    }
}

public class DeleteFromNthNode
{
    public static Node insertNode(Node head,int value)
    {
        Node newNode = new Node(value);
        if(head==null)
            return newNode;
        Node temp = head;
        while(temp.next!=null)
            temp = temp.next;
        temp.next = newNode;
        return head;
    }

    public static void traverseList(Node root)
    {
        while(root!=null)
        {
            System.out.println(root.data);
            root = root.next;
        }
    }
    public static Node deleteNthFromEnd(Node head,int n)
    {
        Node forLen = head;
        if(head==null)
            return null;
        int len = 0;
        while(forLen!=null)
        {
            forLen = forLen.next;
            len++;
        }
        if (n > len)
        {
            System.out.println("Invalid position");
            return head;
        }
        if (n == len)
        {
            return head.next;
        }
        int deletePos = len - n ;
        Node temp = head ;
        for(int i=1;i<deletePos;i++)
            temp = temp.next;
        temp.next = temp.next.next;


        return head;
    }

    public static void main(String[] args)
    {
        Node head = new Node(10);

        // Insert nodes into the linked list
        head = insertNode(head, 15);
        head = insertNode(head, 20);
        head = insertNode(head, 30);
        head = deleteNthFromEnd(head, 2);

        // Traverse and print the linked list
        System.out.println("Linked List:");
        traverseList(head);


    }


}
