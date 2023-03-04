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
    } else {
        cout << "���m�W�w�s�b�I\n";
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

// �R�����ʾ�
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
        cout << "�п��J�ާ@�G\n"
             << "i: �s�W�`�I\n"
             << "d: �R���m�W�ۦP�`�I\n"
             << "r: �R���s���ۦP�`�I\n"
             << "f: �d���m�W�ۦP�`�I\n"
             << "l: �L�X�`�I���e\n"
             << "q: ���}�{��\n";
        cin >> choice;
        switch (choice) {
            case 'i': {
                string name, phone;
                cout << "�п��J�m�W�M�q�ܡA�H�Ů��j�}�G";
                cin >> name >> phone;
                root = insertNode(root, name, phone, rand() % 1000000 + 1);
                cout << "�I";
                break;
            }
            case 'd': {
                string name;
                cout << "�п��J���R�����m�W�G";
                cin >> name;
                root = deleteByName(root, name);
                break;
            }
            case 'r': {
                int id;
                cout << "�п��J���R�����s���G";
                cin >> id;
                root = deleteById(root, id);
                break;
            }
            case 'f': {
                string name;
                cout << "�п��J���d�䪺�m�W�G";
                cin >> name;
                TreeNode* node = findByName(root, name);
                if (node != NULL) {
                    cout << "�`�I�s���G" << node->id << "\n";
                    cout << "�m�W�G" << node->name << "\n";
                    cout << "�q�ܡG" << node->phone << "\n";
                } else {
                    cout << "�䤣���ŦX���󪺸`�I�I\n";
                }
                break;
            }
            case 'l': {
                cout << "\n���ǹM���G";
                printPreorder(root);
                cout << "���ǹM���G";
                printInorder(root);
                cout << "\n���ǹM���G";
                printPostorder(root);
                cout << "\n";
                break;
            }
            case 'q': {
                deleteTree(root);
                cout << "�{���w�����C\n";
                return 0;
            }
            default:
                cout << "�L�Ī����J�I\n";
                break;
        }
    }
}

