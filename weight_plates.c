//  A Program that takes an input file full of data and sorts it in an output file
//
//  Created by Milan Patel on 4/21/19.
//  Copyright © 2019 Milan Patel. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


//  Define Structure
struct plate
{
    float weight;
    char color[100];
    int quantity;
};


//  Sort Function
void selection_sort(struct plate array_plates[], int n)
{
    int i, j;
    int index;
    struct plate temp;
    
    //  Array for sort
    for (i = 0; i < n-1; i++)
    {
        //  Find min index
        index = i;
        for (j = i+1; j < n; j++)
        {
            //  Compare elements
            if (array_plates[j].weight < array_plates[index].weight)
            {
                //  Update min index
                index = j;
            }
        }
        
        //  Swap
        temp = array_plates[index];
        array_plates[index] = array_plates[i];
        array_plates[i] = temp;
    }
}


//  Main function
int main()
{
    //  Set Structure Array
    struct plate plates[100];
    int i, counter=0;
    struct plate temp;
    
    //  Open file
    FILE *fp, *ofp;
    fp = fopen("plates.txt", "r");
    ofp = fopen("ordered_plates.txt", "w");
    
    //  Read plates data
    while((fscanf(fp, "%f %s %d", &temp.weight, temp.color, &temp.quantity)) == 3)
    {
        //Store data in array
        plates[counter] = temp;
        counter++;
    }
    
    //Close input file
    fclose(fp);
    
    //Sort data
    selection_sort(plates, counter);
    
    //Write output
    for(i=0; i<counter; i++)
    {
        fprintf(ofp, "%.2f %s %d\n", plates[i].weight, plates[i].color, plates[i].quantity);
    }
    
    //Close files
    fclose(ofp);
    fclose(ofp);
    
    return 0;
}
