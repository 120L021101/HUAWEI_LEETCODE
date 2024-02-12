

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define equals(x, y, e) (abs(x - y) <= e)
#define belongs(x, y, start1, end1, start2, end2, e) ( \
    ((start1 - e <= x && x <= start2 + e) || (start2 - e <= x && x <= start1 + e)) \
 && ((end1 - e <= y && y <= end2 + e) || (end2 - e <= y && y <= end1 + e)) \
)
#define include(x1, y1, x2, y2, x, y, e) ( \
    equals((x2 - x1) * (y - y1), (y2 - y1) * (x - x1), e) \
 && belongs(x, y, x1, y1, x2, y2, e) \
)

double* intersection(int* start1, int start1Size, int* end1, int end1Size, int* start2, int start2Size, int* end2, int end2Size, int* returnSize){
    double epsilon = 1e-6;    
    *returnSize = 0;
    double* dot = NULL;
    double DB[2] = {
        (end1[0] * start1[1] - start1[0] * end1[1]),
        (end2[0] * start2[1] - start2[0] * end2[1])
    };
    double DX[2] = {
        (start1[1] - end1[1]),
        (start2[1] - end2[1])
    };
    double DY[2] = {
        (end1[0] - start1[0]),
        (end2[0] - start2[0])
    };
    double D = DY[0] * DX[1] - DY[1] * DX[0];
    if (equals(D, 0, epsilon)) {
        double min_x = 0, min_y = 0;
        if (include(start2[0], start2[1], end2[0], end2[1], start1[0], start1[1], epsilon)) {
            min_x = start1[0];
            min_y = start1[1];
            *returnSize = 2;
        }
        if (*returnSize && (end1[0] > min_x || (end1[0] == min_x && end1[1] > min_y))){}
        else if (include(start2[0], start2[1], end2[0], end2[1], end1[0], end1[1], epsilon)) {
            min_x = end1[0];
            min_y = end1[1];
            *returnSize = 2;
        }
        if (*returnSize && (start2[0] > min_x || (start2[0] == min_x && start2[1] > min_y))){}
        else if (include(start1[0], start1[1], end1[0], end1[1], start2[0], start2[1], epsilon)) {
            min_x = start2[0];
            min_y = start2[1];
            *returnSize = 2;
        }
        if (*returnSize && (end2[0] > min_x || (end2[0] == min_x && end2[1] > min_y))){}
        else if (include(start1[0], start1[1], end1[0], end1[1], end2[0], end2[1], epsilon)) {
            min_x = end2[0];
            min_y = end2[1];
            *returnSize = 2;
        }
        if (!*returnSize) return dot; // NULL dot

        dot = (double *)malloc(sizeof(double) * (*returnSize));
        dot[0] = min_x; dot[1] = min_y;
        return dot;
    }
    double Dy = (DB[0] * DX[1] - DB[1] * DX[0]) / D;
    double Dx = (DY[0] * DB[1] - DY[1] * DB[0]) / D;
    if (!belongs(Dx, Dy, start1[0], start1[1], end1[0], end1[1], epsilon)
          || !belongs(Dx, Dy, start2[0], start2[1], end2[0], end2[1], epsilon)){
        return dot;
    }
    *returnSize = 2;
    dot = (double *)malloc(sizeof(double) * (*returnSize));
    dot[0] = Dx; dot[1] = Dy;
    return dot;
}
