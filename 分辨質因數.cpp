#include <iostream>
#include <vector>
#include <stdlib.h> 

using namespace std;

//定義鏈結串列節點
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//判斷是否為質數
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

//列出n的因數並將因數放入鏈結串列中
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

//印出鏈結串列
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
    cout << "請輸入一個數字n：";
    cin >> n;
    vector<int> factors;
    ListNode* head = getFactors(n, factors);
    cout << "n的因數為：";
    for(int i=0; i<factors.size(); i++){
        cout << factors[i] << " ";
    }
    cout << endl;
    int choice = 0;
    while(choice != 3){
        cout << "請選擇印出順序：1.順序 2.反序 3.離開：";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "n的質因數順序為：";
                printList(head);
                break;
            case 2:
                cout << "n的質因數反序為：";
                printList(head, true);
                break;
            case 3:
                cout << "結束程式。" << endl;
                break;
            default:
                cout << "請輸入1、2或3。" << endl;
                break;
        }
    }
    return 0;
}
