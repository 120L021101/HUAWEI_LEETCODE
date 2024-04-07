import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

class InhTreeNode {
    private String name;
    private boolean isDead;
    private List<InhTreeNode> children;

    public InhTreeNode(String name) {
        this.name = name;
        this.isDead = false;
        children = new LinkedList<>();
    }
    public String getName() {
        return name;
    }
    public boolean ifDead() {
        return this.isDead;
    }
    public List<InhTreeNode> getChildren() {
        // unsafe return
        return children;
    }
    public void addChild(InhTreeNode child) {
        children.add(child);
    }
    public void setDeath() {
        isDead = true;
    }
}

class ThroneInheritance {

    private InhTreeNode rootKing;
    private Map<String, InhTreeNode> loci_map; 

    public ThroneInheritance(String kingName) {
        rootKing = new InhTreeNode(kingName);
        loci_map = new HashMap<>();
        loci_map.put(kingName, rootKing);
    }
    
    public void birth(String parentName, String childName) {
        InhTreeNode parentNode = loci_map.get(parentName);
        InhTreeNode childNode = new InhTreeNode(childName);
        loci_map.put(childName, childNode);
        parentNode.addChild(childNode);
    }
    
    public void death(String name) {
        InhTreeNode deadNode = loci_map.get(name);
        deadNode.setDeath();
    }
    
    public List<String> getInheritanceOrder() {
        List<String> retOrder = new LinkedList<>();
        dfs(rootKing, retOrder);
        return retOrder;
    }

    private void dfs(InhTreeNode node, List<String> retOrder) {
        if (!node.ifDead()) {
            retOrder.add(node.getName());
        }
        for (InhTreeNode child : node.getChildren()) {
            dfs(child, retOrder);
        }
    }
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance obj = new ThroneInheritance(kingName);
 * obj.birth(parentName,childName);
 * obj.death(name);
 * List<String> param_3 = obj.getInheritanceOrder();
 */