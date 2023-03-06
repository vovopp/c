#include <iostream>
#include <vector>
#include <stdlib.h> 

using namespace std;

//�w�q�쵲��C�`�I
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//�P�_�O�_�����
bool isPrime(int num){
    if(num < 2){
        return false;
    }
    for(int i=2; i*i<=num; i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

//�C�Xn���]�ƨñN�]�Ʃ�J�쵲��C��
ListNode* getFactors(int n, vector<int>& factors){
    ListNode* head = new ListNode(0);
    ListNode* tail = head;
    for(int i=1; i<=n; i++){
        if(n%i == 0){
            factors.push_back(i);
            ListNode* node = new ListNode(i);
            tail->next = node;
            tail = tail->next;
        }
    }
    tail = head->next;
    while(tail != NULL){
        if(isPrime(tail->val)){
            tail->val *= -1;
        }
        tail = tail->next;
    }
    return head->next;
}

//�L�X�쵲��C
void printList(ListNode* head, bool reverse=false){
    if(head == NULL){
        return;
    }
    vector<int> vals;
    while(head != NULL){
        vals.push_back(head->val);
        head = head->next;
    }
    if(reverse){
    	puts(" ");
        for(int i=vals.size()-1; i>=0; i--){
            cout << abs(vals[i]);
			if(vals[i] < 0){
                cout << " P" ;
            }
            if(vals[i] > 0)
			{
                cout << " N" ;
            } 
            cout << "\n";
        }
    } else{
    	puts(" ");
        for(int i=0; i<vals.size(); i++){
            cout << abs(vals[i]);
            if(vals[i] < 0){
                cout << " P" ;
            }
            if(vals[i] > 0)
			{
                cout << " N" ;
            }
            cout << "\n";
        }
    }
    cout << endl;
}

int main(){
    int n;
    cout << "�п�J�@�ӼƦrn�G";
    cin >> n;
    vector<int> factors;
    ListNode* head = getFactors(n, factors);
    cout << "n���]�Ƭ��G";
    for(int i=0; i<factors.size(); i++){
        cout << factors[i] << " ";
    }
    cout << endl;
    int choice = 0;
    while(choice != 3){
        cout << "�п�ܦL�X���ǡG1.���� 2.�ϧ� 3.���}�G";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "n����]�ƶ��Ǭ��G";
                printList(head);
                break;
            case 2:
                cout << "n����]�ƤϧǬ��G";
                printList(head, true);
                break;
            case 3:
                cout << "�����{���C" << endl;
                break;
            default:
                cout << "�п�J1�B2��3�C" << endl;
                break;
        }
    }
    return 0;
}
