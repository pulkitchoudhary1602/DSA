class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* next = head->next;

        int critical = -1;
        int firstcritical = -1;
        int mini = INT_MAX;
        int i = 0;

        while (temp->next != NULL) {
            if (prev != NULL && next != NULL) {
                if ((prev->val < temp->val && temp->val > next->val) ||
                    (prev->val > temp->val && temp->val < next->val)) {

                    if (firstcritical == -1) {
                        firstcritical = i;
                    }
                    else {
                        mini = min(mini, i - critical);
                    }

                    critical = i;
                }
            }

            i++;
            prev = temp;
            temp = next;
            next = next->next;
        }

        if (firstcritical == -1 || firstcritical == critical) {
            return {-1, -1};
        }

        return {mini, critical - firstcritical};
    }
};

