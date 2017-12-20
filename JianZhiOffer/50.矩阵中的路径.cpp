/********************************************************************************
题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径
解题思路：回溯法
如果当前位置的字符与字符串中要访问的相同，则该位置置为访问过，并且在该位置的上下左右去循找
接下来的路径；如果接下来的路径未找到，该位置重置为未访问，回退到前一步重新找路径
********************************************************************************/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == NULL || rows < 1 || cols < 1 || str == NULL)
            return false;
        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);
        int pathLength = 0;
        for(int row = 0; row < rows; ++row)
        {
            for(int col = 0; col < cols; ++ col)
            {
                if(hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
                    return true;
            }
        }
        delete[] visited;
   		visited = NULL;
    	return false;
    }
    
    bool hasPathCore(char* matrix, int rows, int cols, int row, int col, 
                     char* str, int &pathLength, bool* visited)
    {
        if(str[pathLength] == '\0')  //str所有字符都被访问到了，则路径找到
            return true;
        bool haspath = false;
        if(row >= 0 && row < rows && col >=0 && col < cols  //矩阵中当前位置的字符与字符串中要访问的字符相等，并且矩阵该位置未被访问
           && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])  
        {
            ++pathLength;  //指向下一个要访问的字符
            visited[row * cols + col] = true; 
            haspath = hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)  //继续在当前位置的上下左右寻找接下来的路径
                || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited);
            
            if(!haspath)  //未找到下一个字符回退一步
            {
                --pathLength;
            	visited[row * cols + col] = false;
        	}
        }
        
        return haspath;
        
    }
    


};