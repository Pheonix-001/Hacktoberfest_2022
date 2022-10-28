/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution 
{
    public Node connect(Node root) 
    {
        Queue<Node> q = new LinkedList<>();
        if(root!=null)
            q.add(root);
        while(!q.isEmpty())
        {
            int size = q.size();
            Node prev = null;
            while(size-->0)
            {
                Node node = q.poll();
                if(prev!=null)
                    prev.next = node;
                prev = node;
                if(node.left!=null)
                    q.add(node.left);
                if(node.right!=null)
                    q.add(node.right);
            }
        }
        return root;
    }
}
