#include <stdio.h>
#include <math.h>

float solve_det_3(float det_3[3][3])
{
    float sub_det0 =  det_3[0][0]*(det_3[1][1]*det_3[2][2] - det_3[1][2]*det_3[2][1]); 
    float sub_det1 = -det_3[0][1]*(det_3[1][0]*det_3[2][2] - det_3[1][2]*det_3[2][0]);
    float sub_det2 =  det_3[0][2]*(det_3[1][0]*det_3[2][1] - det_3[1][1]*det_3[2][0]);
    return (sub_det0 + sub_det1 + sub_det2);
}


float solve_det(int order, float det[order][order])
{
    float result = 0;
    if(order == 3) result = solve_det_3(det);
    else
    {
        float sub_det[order-1][order-1];
        for(int column = 0; column < order; column++)
        {
            for(int c = 0; c < order-1; c++)
            {
                if(c < column)  for(int r = 0; r < order-1; r++) sub_det[r][c] = det[r+1][c];
                if(c >= column) for(int r = 0; r < order-1; r++) sub_det[r][c] = det[r+1][c+1];   
            }
            result += det[0][column] * pow(-1, column) * solve_det(order-1, sub_det);  
        } 
    }
    return result;
}

int main(void)
{
    printf("\n\n======================================================");
    printf("\nAmar Mohamed\n24/12/2020\nDeterminant calculator\nworks for any nth order determinant.\nEnjoy\n");
    printf("======================================================\n\n");
    int key = 1, order;
    while(key == 1)
    {
        printf("enter determinant order : ");
        scanf("%d", &order);
        printf("\n======================================================\n\n");
        printf("enter determinant row by row, separate elements with tap\n\n");
        float det[order][order];
        for(int r = 0; r < order; r++)
        {
            printf("enter det[%d][*]: ", r);
            for(int c = 0; c < order; c++) scanf("%f", &det[r][c]);
        }
        printf("\n======================================================\n\n");
        printf("result = %.3f\n", solve_det(order, det));
        printf("\n======================================================\n\n");
        printf("do you want to continue ?? (1 yes, 0 no).\nAnswer::");
        scanf("%d", &key);
        printf("\n=======================================================\n\n");
    }
    return 10;
}





