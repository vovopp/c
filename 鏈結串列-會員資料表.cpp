#include <iostream>
#include <string>

using namespace std;

// �إ߸`�I
struct Node {
    string name;
    string email;
    string phone;
    Node* next;
};

// �s�W�`�I���C�̫�
void insertNode(Node* &head, Node* &last, string name, string email, string phone) {
    if (head == NULL) {
        head = last = new Node;
        head->name = name;
        head->email = email;
        head->phone = phone;
        head->next = NULL;
    } else {
        Node* temp = new Node;
        temp->name = name;
        temp->email = email;
        temp->phone = phone;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

// �R���`�I
void deleteNode(Node* &head, string name) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->name == name) {
            if (temp == head) { 
                head = head->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Delete ok" << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Can not delete" << endl;
}

// �j�M�`�I
void findNode(Node* &head, string name) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->name == name) {
            cout << "found" <<"\n"<<temp->name << "\n" << temp->email << "\n" << temp->phone <<"\n" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not found" << endl;
}

// �L�X�`�I
void listNode(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->name << "\n" << temp->email << "\n" << temp->phone <<"\n"<< endl;
        temp = temp->next;
    }
}

//�q�ܸ��X�����Q��ơA�����Q�줧�e���Ʀr��0
void formatPhone(string &phone){
    if(phone.length() < 10){
        int zeroNum = 10 - phone.length();
        string temp;
        for(int i = 0; i < zeroNum;i++){
            temp += "0";
        }
        phone = temp + phone;
    }

}

int main() {
    Node* head = NULL;
    Node* last = NULL;
    string name = "";
    string email = "";
    string phone = "";
    char command = ' ';

    do {
        cin >> command;
        switch (command) {
            case 'i':
                cin >> name >> email >> phone;
                formatPhone(phone);
                insertNode(head, last, name, email, phone);
                break;
            case 'd':
                cin >> name;
                deleteNode(head, name);
                break;
            case 'f':
                cin >> name ;
                findNode(head, name);
                break;
            case 'l':
                listNode(head);
                break;
            
			
        }
    } 

    while (command != 'q');;
}
