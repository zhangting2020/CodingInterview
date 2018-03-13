/*
题目描述
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
  1
      / \
     /   \
    0 --- 2
         / \
         \_/
题目解读：
克隆一个无向图，图中每一个结点包含一个唯一的标签和一系列的相邻结点。{0,1,2# 1,2# 2,2}.表示：0的相邻
结点是1和2,1的相邻结点是2,2的相邻结点是2。
解题思路:
定义一个map：unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;对于{0,1,2# 1,2# 2,2}来说：
要克隆新的图，所以每个结点都要新建，假设新建的0结点为0’。当map里找不到mp[1]时，说明1'还没创建。
key  value 
0      0‘
1      
一个队列nodes用来保存原图的结点，每次弹出一个用来克隆。
1.首先创建新的图的头结点head，mp[node] = head。相当于mp[0] = 0';将原图的第一个node入栈
2.当nodes不为空时：
  弹出原图的当前结点curNode;
  遍历它的neighbors：
      若mp里不包含原图curNode的某个neighbor，则创建新的原图和新图对加入mp;并将原图的这个neighbor入队列
      为新结点加入neighbor
*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;

        map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
        UndirectedGraphNode *head = new UndirectedGraphNode(node->label); //创建副本的第一个结点
        mp[node] = head;
        queue<UndirectedGraphNode*> nodes;
        nodes.push(node);
        while(nodes.size())
        {
            UndirectedGraphNode *curNode = nodes.front();
            nodes.pop();
            for(vector<UndirectedGraphNode*>::iterator it = (curNode->neighbors).begin(); 
                it != (curNode->neighbors).end(); ++it)  //it指向原图的当前结点的neighbors
            {
                 if(mp.find(*it) == mp.end())  //未找到
                 {
                     mp[*it] = new UndirectedGraphNode( (*it)->label ); //创建该节点的副本存入mp中
                     nodes.push(*it);  //注意这里是把原图当前结点的neighbors放进去
                 }
                mp[curNode]->neighbors.push_back(mp[*it]); //为新结点添加neighbor
            }
        }
        return head;
    }
};