class HashNode {
    public int val;
    public HashNode next;
    public HashNode(int val) {
        this.val = val;
        this.next = null;
    }
    public HashNode() {
        this.val = -1;
        this.next = null;
    }
    public HashNode(int val, HashNode next) {
        this.val = val;
        this.next = next;
    }
    public void add(HashNode node) {
        node.next = this.next;
        this.next = node;
    }
    public void remove() {
        this.next = this.next.next;
    }
}
class MyHashSet {

    private static final int hashLength = (int)100 + 7;
    private HashNode[] nodeList;
    public MyHashSet() {
        nodeList = new HashNode[hashLength];
        for (int i = 0; i < nodeList.length; ++i) {
            nodeList[i] = new HashNode();
        }
    }
    
    public void add(int key) {
        int val = key;
        key %= hashLength;
        HashNode node = nodeList[key].next;
        while (node != null) {
            if (node.val == val) return;
            node = node.next;
        }
        nodeList[key].add(new HashNode(val)); 
    }
    
    public void remove(int key) {
        int val = key;
        key %= hashLength;
        HashNode before = nodeList[key];
        HashNode after = before.next;
        while (after != null) {
            if (after.val == val) {
                before.remove();
                break;
            }
            before = after;
            after = after.next;
        }
    }
    
    public boolean contains(int key) {
        int val = key;
        key %= hashLength;
        HashNode node = nodeList[key].next;
        while (node != null) {
            if (node.val == val) {
                return true;
            }
            node = node.next;
        }
        return false;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */