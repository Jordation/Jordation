#include <stdio.h>
#include <stdlib.h>
typedef struct TypeBurger {
    int OrderNumber;
    char BurgerType;
    int burgnum;
    float PRICETEMP;
} TypeBurger;
typedef struct TypeChip {
    int OrderNumber;
    int chipsnum;
} TypeChip;
typedef struct TypeDrink {
    int OrderNumber;
    int drinknum;
} TypeDrink;
typedef struct TypeMeal {
    int OrderNumber;
    // int totalprice
    //i can calculate total price with this syntax
    //void DisplayWithPTR(TypeBurger *ptr){
    //printf("\nburg data from pointer: %d %c
    //%d",ptr->OrderNumber,ptr->BurgerType,ptr->quantity);
    int quantity;
    TypeBurger *mBurgPTR;
    TypeChip *mChipPTR;
    TypeDrink *mDrinkPTR;
} TypeMeal;
typedef struct FULLORDER {
    TypeBurger *BurgssPTR[3];  // create new burger item with burgerfunction
    TypeChip *ChipssPTR[3];    // it has an extra s. its important
    TypeDrink *DrinkssPTR[3];  // u get the point
    TypeMeal *MealssPTR[3];
    float orderprice;
} FULLORDER;

TypeBurger BurgerFunction(int ord, char btype, int num, float price) {
    TypeBurger NewBurger;
    NewBurger.OrderNumber = ord;
    NewBurger.BurgerType = btype;
    NewBurger.burgnum = num;
    NewBurger.PRICETEMP = price;
    return NewBurger;
}
TypeChip ChipFunction(int ord, int num, float price) {
    TypeChip newchip;
    newchip.OrderNumber = ord;
    newchip.chipsnum = num;
    return newchip;
}
TypeDrink DrinkFunction(int ord, int num, float price) {
    TypeDrink newdrink;
    newdrink.OrderNumber = ord;
    newdrink.drinknum = num;
    return newdrink;
}

TypeMeal MealFunction(int i) {
    int MealRequest;
    int quantity;
    TypeChip *chipPTR = NULL, mealschip;
    TypeDrink *drinkPTR = NULL, mealsdrink;
    TypeBurger *burgPTR = NULL, mealsburger;
    TypeMeal cmeal;
    printf(
        "\n----------------\n|which meal to add to the order\n|chicken - "
        "1\n|ham - 2\n|veg - 3\n----------------\n");
    scanf("%d", &MealRequest);
    switch (MealRequest) {
        case 1:
            printf("\nHow many would you like to add to the order?\n");
            scanf("%d", &quantity);
            mealsburger = BurgerFunction(i, 'c', quantity, 5.35);
            mealsdrink = DrinkFunction(i, 1, 4.15);
            mealschip = ChipFunction(i, 1, 1.85);
            burgPTR = &mealsburger;
            drinkPTR = &mealsdrink;
            chipPTR = &mealschip;
            cmeal.OrderNumber = i;
            cmeal.quantity = quantity;
            cmeal.mBurgPTR = burgPTR;
            cmeal.mChipPTR = chipPTR;
            cmeal.mDrinkPTR = drinkPTR;
            return cmeal;
        case 2:
            printf("\nHow many would you like to add to the order?\n");
            scanf("%d", &quantity);
            mealsburger = BurgerFunction(i, 'h', quantity, 5.55);
            burgPTR = &mealsburger;
            // TypeMeal hmeal;
            cmeal.OrderNumber = i;
            cmeal.quantity = quantity;
            cmeal.mChipPTR = chipPTR;
            cmeal.mDrinkPTR = drinkPTR;
            // TypeMeal *hmealPTR = &hmeal;
            return cmeal;
        case 3:
            printf("\nHow many would you like to add to the order?\n");
            scanf("%d", &quantity);
            mealsburger = BurgerFunction(i, 'v', quantity, 5.90);
            burgPTR = &mealsburger;
            // TypeMeal vmeal;
            cmeal.OrderNumber = i;
            cmeal.quantity = quantity;
            cmeal.mChipPTR = chipPTR;
            cmeal.mDrinkPTR = drinkPTR;
            // TypeMeal *vmealPTR = &vmeal;
            return cmeal;
        default:
            printf(
                "Please enter a valid meal option ? the options r there. pick "
                "one.");
    };
}
FULLORDER GodFunction(int i) {
    FULLORDER finord;
    int mc, bc, cc, dc;  // tracks count of each meal added to order
    int mchoice;
    TypeMeal newmeal;
    TypeMeal *nmPTR = NULL;
    TypeBurger newburger;
    TypeBurger *nbPTR = NULL;
    TypeChip newchip;
    TypeChip *ncPTR = NULL;
    TypeDrink newdrink;
    TypeDrink *ndPTR = NULL;
    int loophold = 0;
    while (loophold < 1) {
        printf(
            "\n----------------\n|Place your order here :)\n|1 - Order "
            "Meals\n|2 - Order Burgers\n|3 - Order Chips\n|4 - Order "
            "Drinks\n|5 - Process Order\n|6 - Cancel "
            "Order\n----------------\n");
        scanf("%d", &mchoice);
        switch (mchoice) {
            case 1:
                newmeal = MealFunction(i);
                nmPTR = &newmeal;
                finord.MealssPTR[0] = nmPTR;
                printf("price of order here\n--------\n");
                break;
            case 2:
                nbPTR = &newburger;
                newburger = BurgerFunction(i, 'c', 5, 4.15);
                finord.BurgssPTR[0] = nbPTR;
                printf("price of order here\n--------\n");
                break;
            case 3:
                ncPTR = &newchip;
                newchip = ChipFunction(i, 1, 1.85);
                finord.ChipssPTR[0] = ncPTR;
                printf("price of order here\n--------\n");
                break;
            case 4:
                ndPTR = &newdrink;
                newdrink = DrinkFunction(i, 1, 5.35);
                finord.DrinkssPTR[0] = ndPTR;
                break;
            case 5:
                return finord;
            case 6:
            default:
                printf(
                    "i hope ur debugging.. the listed values r right there . ^ "
                    ":)");
        };
    }
    return finord;
}

// float CalculateRevenue(FULLORDER *orderdata, float currentrevenue){
// loop to check all pointers to types of fullorder
//    i = 0
//    if (i > 0){//if it has been calc'd since last order
//        return currentrevenue;
//    }
//    CalculateRevenue(orderdata,currentrevenue)
//    revenue = revenue +
//    (orderdata->MealssPTR[0]->mBurgPTR->PRICETEMP*orderdata->MealssPTR[0]->quantity;)
//    return  currentrevenue;
//
// void CheckOrderFunction(FULLORDER *readorderPTR,int readordernum){
//    printf("ord num %d\n quantity %d\nburger pointer %p\nchip pointer
//    %p\ndrink pointer %p", readorderPTR->MealssPTR[readorder]->OrderNumber,
//    readorderPTR->MealssPTR[readorder]->quantity,
//    readorderPTR->MealssPTR[0]->mBurgPTR,
//    readorderPTR->MealssPTR[0]->mChipPTR,
//    readorderPTR->MealssPTR[0]->mDrinkPTR);
//}

int main() {
    float revenue = 0.00;
    FULLORDER *ORDERS[5];
    FULLORDER finalorder;
    FULLORDER *finalorderPTR = NULL;
    int i = 0;  // becomes for loop for orders
    int G = 0;
    while (G < 6) {
        printf("Welcome To Burger Purchase Location");
        finalorder = GodFunction(i);
        finalorderPTR = &finalorder;
        ORDERS[G] = finalorderPTR;
        // printf("Revenue is at: %f.2", CalculateRevenue(*orderdata, revenue))
        printf("\noopsie im running to the end of my code\n");
        G++;
    }
    return 1;
}
