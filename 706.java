class HashNode {
    public int value;
    public int key;
    public HashNode next;
    public HashNode(int key, int value) {
        this.value = value;
        this.key = key;
        this.next = null;
    }
    public HashNode() {
        this.value = 0;
        this.key = 0;
        this.next = null;
    }
}

class MyHashMap {

    private static final int hashLength = (int)1e2 + 7;
    private HashNode[] nodeList;
    public MyHashMap() {
        nodeList = new HashNode[hashLength];
        for (int i = 0; i < nodeList.length; ++i) {
            nodeList[i] = new HashNode();
        }
    }

    private int getHash(int key) {
        return key % hashLength;
    }

    private boolean containsKey(int key) {
        int hashKey = getHash(key);
        HashNode node = nodeList[hashKey].next;
        while (node != null) {
            if (node.key == key) {
                return true;
            }
            node = node.next;
        }
        return false;
    }
    
    public void put(int key, int value) {
        int hashKey = key % hashLength;
        if (!containsKey(key)) {
            HashNode node = nodeList[hashKey];
            HashNode newNode = new HashNode(key, value);
            newNode.next = node.next;
            node.next = newNode;
        } else {
            HashNode node = nodeList[hashKey].next;
            while (node != null) {
                if (node.key == key) {
                    break;
                }
                node = node.next;
            }
            if (node != null) {
                node.value = value;
            }
        }
    }
    
    public int get(int key) {
        if (!containsKey(key)) {
            return -1;
        }
        int hashKey = getHash(key);

        HashNode node = nodeList[hashKey].next;
        while (node != null) {
            if (node.key == key) {
                break;
            }
            node = node.next;
        }
        return node.value;
    }
    
    public void remove(int key) {
        if (!containsKey(key)) {
            return;
        }
        int hashKey = getHash(key);
        HashNode node = nodeList[hashKey];
        while (node.next != null) {
            if (node.next.key == key) {
                node.next = node.next.next;
                break;
            }
            node = node.next;
        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */