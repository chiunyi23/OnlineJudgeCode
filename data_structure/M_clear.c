#include <stdio.h>
#include <stdlib.h>
typedef struct Data {
    int ID;
    int score;
    struct Data *next;
} Student;

void show_list(Student *front) {
    Student *current = front;
    while(current!= NULL) {
        printf("%d %d\n", current->ID, current->score);
        current = current->next;
    }
}

void insert_front(Student *front, Student *new_student) {
    front = new_student;
    new_student->next = current_student
}

int main()
{
    int num;
    while(scanf("%d", &num) != EOF) {
        int score, ID;
        Student *front;  //create single node
        front = NULL;

        for(int i = 0; i < num; i++) {
            int done = 0;
            scanf("%d %d", &ID, &score);

            Student *new_student, *prev_student, *current_student;
            // setup one student's value
            new_student = (Student*)malloc(sizeof(Student));
            new_student->ID = ID;
            new_student->score = score;
            new_student->next = NULL;
            if(front == NULL) {
                front = new_student;
            }
            else {
                current_student = front;
                if(score == current_student->score && ID < current_student->ID) {
                    insert_front(front, new_student);
                    continue;
                }
                if(score < current_student->score) {
                    insert_front(front, new_student);
                    continue;
                }
                else {
                    while(current_student->next != NULL) {
                        prev_student = current_student;
                        current_student = current_student->next;
                        if(score < current_student->score) {     /* insert inside list */
                            new_student->next = current_student;
                            prev_student->next = new_student;
                            done = 1;
                            break;
                        }
                        if(score == current_student->score) {
                            if(ID < current_student->ID) {     /* insert inside list */
                                new_student->next = current_student;
                                prev_student->next = new_student;
                                done = 1;
                                break;
                            }    
                        }
                    }
                    if(done != 1){
                        current_student->next = new_student; /* insert into end of list */
                    }
                }
            }
        }
         show_list(front);
    }

    return 0;
}
