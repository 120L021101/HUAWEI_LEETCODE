bool oneEditAway(char* first, char* second){
    int length1 = strlen(first);
    int length2 = strlen(second);

    int diff = length1 - length2;
    if (diff < -1 || diff > 1)
        return false;
    
    bool potential_insertion = diff == -1;
    bool potential_deletion = diff == 1;
    bool potential_substitute = diff == 0;
    
    char* end1 = first + length1;
    char* end2 = second + length2;
    char* pointer1 = first;
    char* pointer2 = second;

    while (pointer1 != end1) {
        if (*pointer1 != *pointer2) {
            if (!potential_insertion && !potential_deletion && !potential_substitute)
                return false;
            if (potential_insertion) {
                pointer2 ++;
                potential_insertion = false;
            }
            if (potential_deletion) {
                pointer1 ++;
                potential_deletion = false;
            }
            if (potential_substitute) {
                pointer1 ++;
                pointer2 ++;
                potential_substitute = false;
            }
        }
        else {
            pointer1 ++;
            pointer2 ++;
        }
    }
    return true;
}
