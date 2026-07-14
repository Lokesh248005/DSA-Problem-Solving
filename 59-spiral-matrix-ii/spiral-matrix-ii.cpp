class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));        
        int ele =0;
        int top=0;int right =n-1;int left =0;int bottom =n-1;
        while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ele++;
            matrix[top][i]=ele;}
        top++;
        for(int i=top;i<=bottom;i++){
            ele++;
            matrix[i][right]=ele;
        }
        right--;
        for(int i =right;i>=left;i--){
            ele++;
            matrix[bottom][i]=ele;
        }
        bottom--;
        for(int i=bottom;i>=top;i--){
            ele++;
            matrix[i][left]=ele;
            
        }
        left++;
    }
    return matrix;
    
    }

};