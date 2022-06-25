#include <stdio.h>
#include <stdlib.h>

struct NODE 
{
  int data;
  int priority;
  NODE *left, *right;
  //Hàm Tạo
  NODE(int data, int priority)
  {
    this->data = data;
    this->priority = priority;
    this->left = NULL;
    this->right = NULL;
  }
};

// Duyệt giữa cây có nút gốc là root
void inorder(NODE *root) 
{
  if (root != NULL) {
    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
  }
}

// Chèn nút với data và độ ưu tiên vào cây.
NODE *Insert(NODE *node, int data, int priority) {
  //Nếu node bằng NULL thì tạo mới một node
  if (node == NULL) return new NODE(data, priority);
  //Tìm vị trí phù hợp cho node mới
  if (priority < node->priority)
    node->left = Insert(node->left, data, priority);
  else
    node->right = Insert(node->right, data, priority);
  return node;
}

//Tìm node có độ ưu tiên cao nhất
NODE *RemoveMax(NODE *&node) {
  NODE *current = node;
  //Trường hợp cây không có cây con phải. Node gốc có độ ưu tiên cao nhất.
  if(node->right == NULL)
  {
    //Lưu lại node gốc vào maxPri
    NODE *maxPri = node;
    //Gán lại node gốc mới
    node = node->left;
    return maxPri;
  }
  //Phần tử có độ ưu tiên cao nhất là phần tử xa nhất về phía bên phải (right most)
  while (current && current->right->right != NULL)
    current = current->right;
  //Lưu lại phần tử right most
  NODE *maxPri = current->right;
  //Nếu phần tử right most có cây con trái. Điều chỉnh lại liên kết.
  if(maxPri->left != NULL)
    current->right = maxPri->left;
  else
    current->right = NULL;
  return maxPri;
}
int main() {
  //Tạo một priorityQueue để lưu các số nguyên.
  NODE *root = NULL;
  //Phát sinh ngẫu nhiên 20 số nguyên có độ ưu tiên là giá trị các số nguyên đó và insert vào priorityQueue.
  for(int i = 0; i < 20; i++)
  {
    int x  = rand()%50;
    root = Insert(root, x, x);
  } 
  //Duyệt giữa in các node của cây theo thứ tự tăng dần
  printf("Inorder traversal: ");
  inorder(root);
  //Gỡ bỏ từng phần tử có độ ưu tiên cho đến khi hàng đợi rỗng
  while(root != NULL)
  {
    NODE *max = RemoveMax(root);
    printf("\n max: %d\n", max->data);
    printf("Inorder traversal: ");
    inorder(root);
  }
}