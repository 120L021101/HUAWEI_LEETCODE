import java.util.LinkedList;
import java.util.List;

class Solution {
    private int opFunc(int val1, int val2, Character op) {
        switch (op) {
            case '+':
                return val1 + val2;        
            case '-':
                return val1 - val2;
        }
        return 0;
    }
    private boolean isNumber(Character ch) {
        return '0' <= ch && ch <= '9';
    }
    public int calculate(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == ' ') continue;
            sb.append(s.charAt(i));
        }
        if (sb.charAt(0) == '-') {
            sb.insert(0, "0");
        }
        StringBuilder sb2 = new StringBuilder();
        for (int i = 0; i < sb.length(); ++i) {
            if (sb.charAt(i) == '-' && sb.charAt(i - 1) == '(') {
                sb2.append("0-");
            } else {
                sb2.append(sb.charAt(i));
            }
        }
        sb = sb2;
        List<Character> op_stack = new LinkedList<>();
        List<Integer> val_stack = new LinkedList<>();
        for (int i = 0; i < sb.length(); ++i) {
            char ch = sb.charAt(i);
            if (isNumber(ch)) {
                StringBuilder val_sb = new StringBuilder(Character.toString(ch));
                while (i + 1 < sb.length() && isNumber(sb.charAt(i + 1))) {
                    i ++;
                    val_sb.append(Character.toString(sb.charAt(i)));
                }
                val_stack.add(0, Integer.valueOf(val_sb.toString()));
            }
            switch (ch) {
                case '+':
                    while (!op_stack.isEmpty()) {
                        char top_op = op_stack.get(0);
                        if (top_op == '(') break;
                        op_stack.remove(0);
                        int op_val2 = val_stack.remove(0);
                        int op_val1 = val_stack.remove(0);
                        val_stack.add(0, opFunc(op_val1, op_val2, top_op));
                    }
                    op_stack.add(0, ch);
                    break;
                case '-':
                    while (!op_stack.isEmpty()) {
                        char top_op = op_stack.get(0);
                        if (top_op == '(') break;
                        op_stack.remove(0);
                        int op_val2 = val_stack.remove(0);
                        int op_val1 = val_stack.remove(0);
                        val_stack.add(0, opFunc(op_val1, op_val2, top_op));
                    }
                    op_stack.add(0, ch);
                    break;
                case '(':
                    op_stack.add(0, ch);
                    break;
                case ')':
                    while (true) {
                        char top_op = op_stack.remove(0);
                        if (top_op == '(') {
                            break;
                        }
                        int op_val2 = val_stack.remove(0);
                        int op_val1 = val_stack.remove(0);
                        val_stack.add(0, opFunc(op_val1, op_val2, top_op));
                    }
                    break;
            }
        }
        while (!op_stack.isEmpty()) {
            char top_op = op_stack.remove(0);
            int op_val2 = val_stack.remove(0);
            int op_val1 = val_stack.remove(0);
            val_stack.add(0, opFunc(op_val1, op_val2, top_op));
        }
        return val_stack.get(0);
    }
}