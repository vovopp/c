#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct TreeNode {
    int id;
    string name;
    string phone;
    TreeNode* left;
    TreeNode* right;
};

/*TreeNode* insertNode(TreeNode* root, string name, string phone, int id);
TreeNode* deleteByName(TreeNode* root, string name);
TreeNode* deleteById(TreeNode* root, int id);
void printByName(TreeNode* root);
void printInorder(TreeNode* root);
void printPreorder(TreeNode* root);
void printPostorder(TreeNode* root);
TreeNode* findByName(TreeNode* root, string name);
void deleteTree(TreeNode* root); */

TreeNode* insertNode(TreeNode* root, string name, string phone, int id) {
    if (root == NULL) {
        root = new TreeNode;
        root->name = name;
        root->phone = phone;
        root->id = id;
        root->left = root->right = NULL;
    } else if (name < root->name) {
        root->left = insertNode(root->left, name, phone, id);
    } else if (name > root->name) {
        root->right = insertNode(root->right, name, phone, id);
    } 
    return root;
}
TreeNode* deleteByName(TreeNode* root, string name) {
    if (root == NULL) {
        return NULL;
    }
    if (name < root->name) {
        root->left = deleteByName(root->left, name);
    } else if (name > root->name) {
        root->right = deleteByName(root->right, name);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->id = temp->id;
        root->name = temp->name;
        root->phone = temp->phone;
        root->right = deleteByName(root->right, temp->name);
    }
    return root;
}
TreeNode* deleteById(TreeNode* root, int id) {
    if (root == NULL) {
        return NULL;
    }
    if (id < root->id) {
        root->left = deleteById(root->left, id);
    } else if (id > root->id) {
        root->right = deleteById(root->right, id);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->id = temp->id;
        root->name = temp->name;
        root->phone = temp->phone;
        root->right = deleteByName(root->right, temp->name);
    }
    return root;
}
void printByName(TreeNode* root) {
    if (root != NULL) {
        printByName(root->left);
        cout << root->name << ": " << root->phone << "\n";
        printByName(root->right);
    }
}

void printInorder(TreeNode* root) {
    if (root != NULL) {
        printInorder(root->left);
        cout << root->name << " ";
        printInorder(root->right);
    }
}

void printPreorder(TreeNode* root) {
    if (root != NULL) {
        cout << root->name << " " <<"\n";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}
void printPostorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->name << " ";
}
TreeNode* findByName(TreeNode* root, string name) {
    if (root == NULL) {
        return NULL;
    }
    if (root->name == name) {
        return root;
    }
    TreeNode* leftResult = findByName(root->left, name);
    if (leftResult != NULL) {
        return leftResult;
    }
    TreeNode* rightResult = findByName(root->right, name);
    if (rightResult != NULL) {
        return rightResult;
    }
    return NULL;
}

// 嚙磋嚙踝蕭嚙踝蕭嚙褊橘蕭
void deleteTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main() {
    TreeNode* root = NULL;
    char choice;
    while (true) {
        cout << "請輸入操作：\n"
             << "i: 新增節點\n"
             << "d: 刪除姓名相同節點\n"
             << "r: 刪除編號相同節點\n"
             << "f: 尋找姓名相同節點\n"
             << "l: 印出節點內容\n"
             << "q: 離開程式\n";
        cin >> choice;
        switch (choice) {
            case 'i': {
                string name, phone;
                cout << "請輸入姓名和電話，以空格隔開;";
                cin >> name >> phone;
                root = insertNode(root, name, phone, rand() % 1000000 + 1);
                break;
            }
            case 'd': {
                string name;
                cout << "請輸入欲刪除的姓名：";
                cin >> name;
                root = deleteByName(root, name);
                break;
            }
            case 'r': {
                int id;
                cout << "請輸入欲刪除的編號：";
                cin >> id;
                root = deleteById(root, id);
                break;
            }
            case 'f': {
                string name;
                cout << "請輸入欲查找的姓名：";
                cin >> name;
                TreeNode* node = findByName(root, name);
                if (node != NULL) {
                    cout << "節點編號：" << node->id << "\n";
                    cout << "姓名：" << node->name << "\n";
                    cout << "電話：" << node->phone << "\n";
                } else {
                    cout << "找不到符合條件的節點！\n";
                }
                break;
            }
            case 'l': {
                cout << "先序列印:"<<"\n";
                printPreorder(root);
                cout << "\n中序列印:"<<"\n";
                printInorder(root);
                cout << "\n後序列印:"<<"\n";
                printPostorder(root);
                cout << "\n";
                break;
            }
            case 'q': {
                deleteTree(root);
                cout << "程式結束。\n";
                return 0;
            }
            default:
                cout << "錯誤的指令" <<"\n";
                break;
        }
    }
}

