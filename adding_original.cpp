
# struct Node {
#     int data;
#     struct Node* next;
#     Node(int x) {
#         data = x;
#         next = NULL;
#     }
# };



class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node * rev_list(struct Node * head){
        struct Node* prev=NULL;
        while(head!=NULL){
            struct Node * temp=head;
            head=head->next;
            temp->next=prev;
            prev=temp;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        struct Node* head;
        struct Node* ptr;
        
        int carry=0;
        
        struct Node * revhead1;
        struct Node * revhead2;
        
        revhead1=rev_list(first);
        revhead2=rev_list(second);
      
        
        struct Node* temp1=revhead1;
         struct Node* temp2=revhead2;
         
         int s;
         int c=0;
         
         while (temp1!=NULL || temp2!=NULL){
              s=0;
             if (temp1!=NULL && temp2!=NULL ){
             s+=(temp1->data+temp2->data+carry);
             if (s>=10){
                 struct Node* t=new Node((s%10));
                 carry=1;
                 if (c==0){
                     head=t;
                     ptr=head;
                     c++;
                 }
                 else{
                 ptr->next=t;
                 ptr=t;}
                 
             }
             else{
                  struct Node* t=new Node(s);
                  carry=0;
                  if (c==0){
                     head=t;
                     ptr=head;
                     c++;
                 }
                 else{
                 ptr->next=t;
                 ptr=t;}
             }
             temp1=temp1->next;
             temp2=temp2->next;
             if ((temp1==NULL && temp2==NULL) && carry==1){
                  struct Node* t=new Node(1);
                   ptr->next=t;
                 ptr=t;
             }
             
         }
         else if (temp1==NULL){
             if (carry==1){
                 s+=(carry+temp2->data);
                 if (s>=10){
                     struct Node* t=new Node((s%10));
                     carry=1;
                     ptr->next=t;
                     ptr=t;
                 }
                 else{
                     struct Node* t=new Node(s);
                     carry=0;
                     ptr->next=t;
                     ptr=t;
                 }
                 temp2=temp2->next;
             }
             else{
                 struct Node* t=new Node(temp2->data);
                 ptr->next=t;
                 ptr=t;
                 temp2=temp2->next;
             }
             if (temp2==NULL && carry==1){
                 struct Node* t=new Node(1);
                   ptr->next=t;
                 ptr=t; 
             }
             
         }
         else{
             if (carry==1){
                 s+=(carry+temp1->data);
                 if (s>=10){
                     struct Node* t=new Node((s%10));
                     carry=1;
                     ptr->next=t;
                     ptr=t;
                 }
                 else{
                     struct Node* t=new Node(s);
                     carry=0;
                     ptr->next=t;
                     ptr=t;
                 }
                 temp1=temp1->next;
             }
             else{
                 struct Node* t=new Node(temp1->data);
                 ptr->next=t;
                 ptr=t;
                 temp1=temp1->next;
             }
             if (temp1==NULL && carry==1){
                 struct Node* t=new Node(1);
                   ptr->next=t;
                 ptr=t; 
             }
             
         }
         
         }
         struct Node* res=rev_list(head);
         return res;
        
        
        
        
        
    }