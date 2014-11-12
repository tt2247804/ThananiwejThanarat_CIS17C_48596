/* 
 * File:   main.cpp
 * Author: Thanarat Thananiwej
 * Created on November 11, 2014, 1:00 PM
 * Purpose:  Project
 */

#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

//Struct of Price and Description
struct PriceDesc
{
	double price;
	string desc;
};

//Functions Prototype
void mainMenu();

void printDrink(map<string, double> &drink);

void orderDrink(map<string, double> &drink, queue<string> &order, multiset<double> &price);

void printMenu(map<string, PriceDesc> &menu);

void printQuickMenu(vector< pair<string, double> > &vs);

void orderMenu(vector< pair<string, double> > &vs, queue<string> &order, multiset<double> &price);

void printDessert(map<string, double> &des);

void orderDessert(map<string, double> &des, queue<string> &order, multiset<double> &price);

void printOrder(queue<string> order);

double total(multiset<double> &price);

void removeOrder(queue<string> &order);

void removeTotal(multiset<double> &price);

int main()
{
	//Create Drink Menu
	map<string, double> drink;

	//Fill in Drink Menu
	drink.insert( pair<string, double>("Coke", 1.99) );
	drink.insert( pair<string, double>("Sprite", 1.99) );
	drink.insert( pair<string, double>("Diet Coke", 1.99) );
	drink.insert( pair<string, double>("Lemonade", 1.99) );
	drink.insert( pair<string, double>("Iced Tea", 1.99) );
	drink.insert( pair<string, double>("Hot Tea", 1.99) );
	drink.insert( pair<string, double>("Hot Coffee", 1.99) );
	drink.insert( pair<string, double>("Hot Chocolate", 2.25) );
	drink.insert( pair<string, double>("Hot Milk", 2.25) );
	drink.insert( pair<string, double>("Thai Iced Tea", 2.25) );
	drink.insert( pair<string, double>("Thai Iced Coffee", 2.25) );
	drink.insert( pair<string, double>("Orange Juice", 2.49) );
	drink.insert( pair<string, double>("Mango Juice", 2.49) );
	drink.insert( pair<string, double>("Guava Juice", 2.49) );
	drink.insert( pair<string, double>("Coconut Juice", 2.49) );

	//Create Food Menu
	map<string, PriceDesc> menu;
	vector< pair<string, double> > vs;
	
	//Fill in Food Menu
	string n1 = "THAI B.B.Q. CHICKEN";
	PriceDesc pd1;
	pd1.price = 6.95;
	pd1.desc = "Barbeque in authentic Thai herb and spices.";
	pair<string, PriceDesc> p1(n1, pd1);
	menu.insert(p1);
	pair<string, double> pair1(n1, pd1.price);
	vs.push_back(pair1);

	string n2 = "ORANGE CHICKEN";
	PriceDesc pd2;
	pd2.price = 6.95;
	pd2.desc = "Glazed chicken nuggets cooked in house special sauce made with orange juice.";
	pair<string, PriceDesc> p2(n2, pd2);
	menu.insert(p2);
	pair<string, double> pair2(n2, pd2.price);
	vs.push_back(pair2);

	string n3 = "SPICY EGGPLANT";
	PriceDesc pd3;
	pd3.price = 6.95;
	pd3.desc = "Chicken with eggplant, bell pepper, carrots, onions and basil leaves.";
	pair<string, PriceDesc> p3(n3, pd3);
	menu.insert(p3);
	pair<string, double> pair3(n3, pd3.price);
	vs.push_back(pair3);

	string n4 = "CASHEW NUT CHICKEN";
	PriceDesc pd4;
	pd4.price = 6.95;
	pd4.desc = "Fried chicken with cashew nuts, chestnuts, and bell peppers in a house sauce.";
	pair<string, PriceDesc> p4(n4, pd4);
	menu.insert(p4);
	pair<string, double> pair4(n4, pd4.price);
	vs.push_back(pair4);

	string n5 = "RAMA LONG-SONG";
	PriceDesc pd5;
	pd5.price = 6.95;
	pd5.desc = "Sauteed beef with peanut sauce and steamed baby spinach.";
	pair<string, PriceDesc> p5(n5, pd5);
	menu.insert(p5);
	pair<string, double> pair5(n5, pd5.price);
	vs.push_back(pair5);

	string n6 = "GARLIC PEPPER";
	PriceDesc pd6;
	pd6.price = 6.95;
	pd6.desc = "Chicken stir-fried in light soy sauce with onions and bell peppers.";
	pair<string, PriceDesc> p6(n6, pd6);
	menu.insert(p6);
	pair<string, double> pair6(n6, pd6.price);
	vs.push_back(pair6);

	string n7 = "SWEET & SOUR";
	PriceDesc pd7;
	pd7.price = 6.95;
	pd7.desc = "Chicken stir-fried with onions, tomatoes, and pineapple in sour sauce.";
	pair<string, PriceDesc> p7(n7, pd7);
	menu.insert(p7);
	pair<string, double> pair7(n7, pd7.price);
	vs.push_back(pair7);

	string n8 = "SPICY MINT LEAVES";
	PriceDesc pd8;
	pd8.price = 6.95;
	pd8.desc = "Chicken sauteed with chili, garlic, bell peppers, and mint leaves.";
	pair<string, PriceDesc> p8(n8, pd8);
	menu.insert(p8);
	pair<string, double> pair8(n8, pd8.price);
	vs.push_back(pair8);

	string n9 = "VEGGIE DELIGHT";
	PriceDesc pd9;
	pd9.price = 6.95;
	pd9.desc = "Authentic Thai stir-fried mixed vegetables with chicken.";
	pair<string, PriceDesc> p9(n9, pd9);
	menu.insert(p9);
	pair<string, double> pair9(n9, pd9.price);
	vs.push_back(pair9);

	string n10 = "GREEN CURRY";
	PriceDesc pd10;
	pd10.price = 6.95;
	pd10.desc = "Chicken in a green curry sauce with bamboo shoots and basil.";
	pair<string, PriceDesc> p10(n10, pd10);
	menu.insert(p10);
	pair<string, double> pair10(n10, pd10.price);
	vs.push_back(pair10);

	string n11 = "MASSAMAN CURRY";
	PriceDesc pd11;
	pd11.price = 6.95;
	pd11.desc = "A mild curry cooked in coconut milk with onions, potatoes and carrots.";
	pair<string, PriceDesc> p11(n11, pd11);
	menu.insert(p11);
	pair<string, double> pair11(n11, pd11.price);
	vs.push_back(pair11);

	string n12 = "PANANG CURRY";
	PriceDesc pd12;
	pd12.price = 6.95;
	pd12.desc = "Chicken in sweet red curry cooked in coconut milk with basil.";
	pair<string, PriceDesc> p12(n12, pd12);
	menu.insert(p12);
	pair<string, double> pair12(n12, pd12.price);
	vs.push_back(pair12);

	string n13 = "YELLOW CURRY";
	PriceDesc pd13;
	pd13.price = 6.95;
	pd13.desc = "A smooth light yellow curry sauce with onions, potatoes, and carrots.";
	pair<string, PriceDesc> p13(n13, pd13);
	menu.insert(p13);
	pair<string, double> pair13(n13, pd13.price);
	vs.push_back(pair13);

	string n14 = "CHICKEN BROCCOLI";
	PriceDesc pd14;
	pd14.price = 6.95;
	pd14.desc = "Stir-fried chicken in garlic and oyster sauce with broccoli and carrots.";
	pair<string, PriceDesc> p14(n14, pd14);
	menu.insert(p14);
	pair<string, double> pair14(n14, pd14.price);
	vs.push_back(pair14);

	string n15 = "PAD THAI";
	PriceDesc pd15;
	pd15.price = 6.95;
	pd15.desc = "Rice noodles stir-fried chicken with crushed peanuts and eggs.";
	pair<string, PriceDesc> p15(n15, pd15);
	menu.insert(p15);
	pair<string, double> pair15(n15, pd15.price);
	vs.push_back(pair15);

	string n16 = "PAD KEE MOW";
	PriceDesc pd16;
	pd16.price = 6.95;
	pd16.desc = "Spicy flat rice noodles with basil, bell peppers, and chicken.";
	pair<string, PriceDesc> p16(n16, pd16);
	menu.insert(p16);
	pair<string, double> pair16(n16, pd16.price);
	vs.push_back(pair16);

	string n17 = "PAD SEE-EW";
	PriceDesc pd17;
	pd17.price = 6.95;
	pd17.desc = "Fried flat rice noodles in soy sauce with broccoli, carrots and chicken.";
	pair<string, PriceDesc> p17(n17, pd17);
	menu.insert(p17);
	pair<string, double> pair17(n17, pd17.price);
	vs.push_back(pair17);

	string n18 = "CHOW MEIN";
	PriceDesc pd18;
	pd18.price = 6.95;
	pd18.desc = "Egg noodles stir-fried with mixed vegetables and chicken.";
	pair<string, PriceDesc> p18(n18, pd18);
	menu.insert(p18);
	pair<string, double> pair18(n18, pd18.price);
	vs.push_back(pair18);

	string n19 = "SPRING ROLLS";
	PriceDesc pd19;
	pd19.price = 5.95;
	pd19.desc = "Glass noodles and vegetables wrapped in egg roll with sweet sauce.";
	pair<string, PriceDesc> p19(n19, pd19);
	menu.insert(p19);
	pair<string, double> pair19(n19, pd19.price);
	vs.push_back(pair19);

	string n20 = "CURRY PUFF";
	PriceDesc pd20;
	pd20.price = 5.95;
	pd20.desc = "Deep fried crispy tofu served with crushed peanuts.";
	pair<string, PriceDesc> p20(n20, pd20);
	menu.insert(p20);
	pair<string, double> pair20(n20, pd20.price);
	vs.push_back(pair20);

	string n21 = "TOFU TODD";
	PriceDesc pd21;
	pd21.price = 5.95;
	pd21.desc = "Deep fried crispy tofu served with crushed peanuts in sour sauce.";
	pair<string, PriceDesc> p21(n21, pd21);
	menu.insert(p21);
	pair<string, double> pair21(n21, pd21.price);
	vs.push_back(pair21);

	string n22 = "VEGETABLE TEMPURA";
	PriceDesc pd22;
	pd22.price = 5.95;
	pd22.desc = "Deep fried carrots, broccoli, zucchini, eggplant, and baby corn.";
	pair<string, PriceDesc> p22(n22, pd22);
	menu.insert(p22);
	pair<string, double> pair22(n22, pd22.price);
	vs.push_back(pair22);

	string n23 = "MEE GROB";
	PriceDesc pd23;
	pd23.price = 5.95;
	pd23.desc = "Crispy caramelized noodles with bell peppers and green onions.";
	pair<string, PriceDesc> p23(n23, pd23);
	menu.insert(p23);
	pair<string, double> pair23(n23, pd23.price);
	vs.push_back(pair23);

	string n24 = "APOLLO SHRIMP";
	PriceDesc pd24;
	pd24.price = 6.95;
	pd24.desc = "Jumbo shrimp on skewer wrapped with marinated chicken mince.";
	pair<string, PriceDesc> p24(n24, pd24);
	menu.insert(p24);
	pair<string, double> pair24(n24, pd24.price);
	vs.push_back(pair24);

	string n25 = "CHICKEN SATAY";
	PriceDesc pd25;
	pd25.price = 6.95;
	pd25.desc = "Glass noodles and vegetables wrapped in egg roll.";
	pair<string, PriceDesc> p25(n25, pd25);
	menu.insert(p25);
	pair<string, double> pair25(n25, pd25.price);
	vs.push_back(pair25);

	string n26 = "MONEY BAGS";
	PriceDesc pd26;
	pd26.price = 6.95;
	pd26.desc = "Golden pastry bags filled with minced chicken and spices.";
	pair<string, PriceDesc> p26(n26, pd26);
	menu.insert(p26);
	pair<string, double> pair26(n26, pd26.price);
	vs.push_back(pair26);

	string n27 = "GOLDEN SHRIMP";
	PriceDesc pd27;
	pd27.price = 6.95;
	pd27.desc = "House battered, golden deep fried shrimp and vegetable.";
	pair<string, PriceDesc> p27(n27, pd27);
	menu.insert(p27);
	pair<string, double> pair27(n27, pd27.price);
	vs.push_back(pair27);

	string n28 = "FRIED WONTON";
	PriceDesc pd28;
	pd28.price = 5.95;
	pd28.desc = "Ground chicken, garlic and pepper wrapped in wonton skin.";
	pair<string, PriceDesc> p28(n28, pd28);
	menu.insert(p28);
	pair<string, double> pair28(n28, pd28.price);
	vs.push_back(pair28);

	string n29 = "FRIED CALAMARI ";
	PriceDesc pd29;
	pd29.price = 6.95;
	pd29.desc = "Calamari tempura served with sweet & sour sauce.";
	pair<string, PriceDesc> p29(n29, pd29);
	menu.insert(p29);
	pair<string, double> pair29(n29, pd29.price);
	vs.push_back(pair29);

	string n30 = "GOLDEN TRIANGLE";
	PriceDesc pd30;
	pd30.price = 5.95;
	pd30.desc = "Ground chicken, garlic and pepper, wrapped in tortillas.";
	pair<string, PriceDesc> p30(n30, pd30);
	menu.insert(p30);
	pair<string, double> pair30(n30, pd30.price);
	vs.push_back(pair30);

	string n31 = "SHRIMP WRAPPED";
	PriceDesc pd31;
	pd31.price = 6.95;
	pd31.desc = "Deep fried shrimp wrapped with ground chicken and egg noodles.";
	pair<string, PriceDesc> p31(n31, pd31);
	menu.insert(p31);
	pair<string, double> pair31(n31, pd31.price);
	vs.push_back(pair31);

	string n32 = "APPETIZER PLATTER ";
	PriceDesc pd32;
	pd32.price = 9.95;
	pd32.desc = "Shrimp tempura, fried calamari, money bags, and vegetable tempura.";
	pair<string, PriceDesc> p32(n32, pd32);
	menu.insert(p32);
	pair<string, double> pair32(n32, pd32.price);
	vs.push_back(pair32);

	string n33 = "TOM KAH SOUP";
	PriceDesc pd33;
	pd33.price = 11.95;
	pd33.desc = "Chicken creamy soup made of coconut milk with lemon grass and mushrooms.";
	pair<string, PriceDesc> p33(n33, pd33);
	menu.insert(p33);
	pair<string, double> pair33(n33, pd33.price);
	vs.push_back(pair33);

	string n34 = "TOM YUM SOUP";
	PriceDesc pd34;
	pd34.price = 11.95;
	pd34.desc = "Chicken with lemon grass, kafir lime leaves, mushrooms, tomatoes and onions.";
	pair<string, PriceDesc> p34(n34, pd34);
	menu.insert(p34);
	pair<string, double> pair34(n34, pd34.price);
	vs.push_back(pair34);

	string n35 = "RICE SOUP";
	PriceDesc pd35;
	pd35.price = 4.95;
	pd35.desc = "Chicken with steamed rice cooked in chicken broth with celery, onions, carrots.";
	pair<string, PriceDesc> p35(n35, pd35);
	menu.insert(p35);
	pair<string, double> pair35(n35, pd35.price);
	vs.push_back(pair35);

	string n36 = "WONTON SOUP";
	PriceDesc pd36;
	pd36.price = 9.95;
	pd36.desc = "Stuffed wontons in special broth with shrimp, celery, onions, carrots.";
	pair<string, PriceDesc> p36(n36, pd36);
	menu.insert(p36);
	pair<string, double> pair36(n36, pd36.price);
	vs.push_back(pair36);

	string n37 = "PO TAK";
	PriceDesc pd37;
	pd37.price = 13.95;
	pd37.desc = "Combination seafood with straw mushrooms, lemongrass, red onions and basil.";
	pair<string, PriceDesc> p37(n37, pd37);
	menu.insert(p37);
	pair<string, double> pair37(n37, pd37.price);
	vs.push_back(pair37);

	string n38 = "VEGETABLE SALAD ";
	PriceDesc pd38;
	pd38.price = 8.95;
	pd38.desc = "Fresh Iceberg Lettuce with bell pepper and fried tofu.";
	pair<string, PriceDesc> p38(n38, pd38);
	menu.insert(p38);
	pair<string, double> pair38(n38, pd38.price);
	vs.push_back(pair38);

	string n39 = "LARB GAl";
	PriceDesc pd39;
	pd39.price = 8.95;
	pd39.desc = "Minced chicken mixed with herbs, chili, lime juice and mint leaves.";
	pair<string, PriceDesc> p39(n39, pd39);
	menu.insert(p39);
	pair<string, double> pair39(n39, pd39.price);
	vs.push_back(pair39);

	string n40 = "BEEF SALAD";
	PriceDesc pd40;
	pd40.price = 8.95;
	pd40.desc = "Grilled sirloin beef in spicy lime juice with cucumbers and mint leaves.";
	pair<string, PriceDesc> p40(n40, pd40);
	menu.insert(p40);
	pair<string, double> pair40(n40, pd40.price);
	vs.push_back(pair40);

	string n41 = "PLA GOONG";
	PriceDesc pd41;
	pd41.price = 9.95;
	pd41.desc = "Grilled shrimp salad with lemon grass, lime juice, tomatoes, and mint leaves";
	pair<string, PriceDesc> p41(n41, pd41);
	menu.insert(p41);
	pair<string, double> pair41(n41, pd41.price);
	vs.push_back(pair41);

	string n42 = "SIAM SALAD";
	PriceDesc pd42;
	pd42.price = 10.95;
	pd42.desc = "Shrimps and chicken with green apples, shredded carrots and cashew nuts.";
	pair<string, PriceDesc> p42(n42, pd42);
	menu.insert(p42);
	pair<string, double> pair42(n42, pd42.price);
	vs.push_back(pair42);

	string n43 = "PAPAYA SALAD";
	PriceDesc pd43;
	pd43.price = 8.95;
	pd43.desc = "Shredded green papaya with lime juice, carrots, green beans, and tomato.";
	pair<string, PriceDesc> p43(n43, pd43);
	menu.insert(p43);
	pair<string, double> pair43(n43, pd43.price);
	vs.push_back(pair43);

	string n44 = "ROAST DUCK SALAD";
	PriceDesc pd44;
	pd44.price = 11.95;
	pd44.desc = "Roast duck finely sliced, mixed with chili and green apple.";
	pair<string, PriceDesc> p44(n44, pd44);
	menu.insert(p44);
	pair<string, double> pair44(n44, pd44.price);
	vs.push_back(pair44);

	string n45 = "RED CURRY";
	PriceDesc pd45;
	pd45.price = 8.95;
	pd45.desc = "A classic Thai curry cooked in coconut milk with bamboo shoots.";
	pair<string, PriceDesc> p45(n45, pd45);
	menu.insert(p45);
	pair<string, double> pair45(n45, pd45.price);
	vs.push_back(pair45);

	string n46 = "ROYAL DUCK CURRY";
	PriceDesc pd46;
	pd46.price = 11.95;
	pd46.desc = "Boneless roast duck cooked in red curry with pine apple.";
	pair<string, PriceDesc> p46(n46, pd46);
	menu.insert(p46);
	pair<string, double> pair46(n46, pd46.price);
	vs.push_back(pair46);

	string n47 = "PINEAPPLE FRIED RICE";
	PriceDesc pd47;
	pd47.price = 10.95;
	pd47.desc = "Shrimp stir-fried with eggs, celery, cashew nuts, raisins and pineapple.";
	pair<string, PriceDesc> p47(n47, pd47);
	menu.insert(p47);
	pair<string, double> pair47(n47, pd47.price);
	vs.push_back(pair47);

	string n48 = "SHRIMP FRIED RICE";
	PriceDesc pd48;
	pd48.price = 11.95;
	pd48.desc = "Fried rice with shrimp, egg, peas, carrots and onion.";
	pair<string, PriceDesc> p48(n48, pd48);
	menu.insert(p48);
	pair<string, double> pair48(n48, pd48.price);
	vs.push_back(pair48);

	string n49 = "CRAB FRIED RICE";
	PriceDesc pd49;
	pd49.price = 13.95;
	pd49.desc = "Fried rice with real crab meat and crab claw with egg, peas, carrot.";
	pair<string, PriceDesc> p49(n49, pd49);
	menu.insert(p49);
	pair<string, double> pair49(n49, pd49.price);
	vs.push_back(pair49);

	string n50 = "SEAFOOD FRIED RICE";
	PriceDesc pd50;
	pd50.price = 13.95;
	pd50.desc = "Combination of seafood with eggs, peas, carrots and onions.";
	pair<string, PriceDesc> p50(n50, pd50);
	menu.insert(p50);
	pair<string, double> pair50(n50, pd50.price);
	vs.push_back(pair50);

	string n51 = "THAI FRIED RICE";
	PriceDesc pd51;
	pd51.price = 8.95;
	pd51.desc = "Chicken fried rice with eggs, onions and peas, carrots.";
	pair<string, PriceDesc> p51(n51, pd51);
	menu.insert(p51);
	pair<string, double> pair51(n51, pd51.price);
	vs.push_back(pair51);

	string n52 = "BANGKOK DELIGHT";
	PriceDesc pd52;
	pd52.price = 11.95;
	pd52.desc = "Sauteed lamb with garlic and pepper, served with steamed broccoli.";
	pair<string, PriceDesc> p52(n52, pd52);
	menu.insert(p52);
	pair<string, double> pair52(n52, pd52.price);
	vs.push_back(pair52);

	string n53 = "BASIL LAMB";
	PriceDesc pd53;
	pd53.price = 11.95;
	pd53.desc = "Sauteed lamb in chili and garlic sauce with bell pepper and sweet basil.";
	pair<string, PriceDesc> p53(n53, pd53);
	menu.insert(p53);
	pair<string, double> pair53(n53, pd53.price);
	vs.push_back(pair53);

	string n54 = "CHILI SHRIMP";
	PriceDesc pd54;
	pd54.price = 11.95;
	pd54.desc = "Stir-fried shrimp in chili sauce with onions, bell peppers, and green onions.";
	pair<string, PriceDesc> p54(n54, pd54);
	menu.insert(p54);
	pair<string, double> pair54(n54, pd54.price);
	vs.push_back(pair54);

	string n55 = "SHRIMP WITH SNOW PEAS";
	PriceDesc pd55;
	pd55.price = 11.95;
	pd55.desc = "Shrimp stir-fried with snow peas and mushrooms.";
	pair<string, PriceDesc> p55(n55, pd55);
	menu.insert(p55);
	pair<string, double> pair55(n55, pd55.price);
	vs.push_back(pair55);

	string n56 = "COCO SALMON";
	PriceDesc pd56;
	pd56.price = 13.95;
	pd56.desc = "Salmon fillet cooked in curry sauce, basil, and a steam spinach.";
	pair<string, PriceDesc> p56(n56, pd56);
	menu.insert(p56);
	pair<string, double> pair56(n56, pd56.price);
	vs.push_back(pair56);

	string n57 = "HEAVEN ON EARTH";
	PriceDesc pd57;
	pd57.price = 13.95;
	pd57.desc = "Deep fried fish fillet cooked in red curry paste, snow peas and sweet basil.";
	pair<string, PriceDesc> p57(n57, pd57);
	menu.insert(p57);
	pair<string, double> pair57(n57, pd57.price);
	vs.push_back(pair57);

	string n58 = "EXOTIC OCEAN";
	PriceDesc pd58;
	pd58.price = 13.95;
	pd58.desc = "Combination seafood in red curry sauce with napa and basil.";
	pair<string, PriceDesc> p58(n58, pd58);
	menu.insert(p58);
	pair<string, double> pair58(n58, pd58.price);
	vs.push_back(pair58);

	string n59 = "PATTAYA SlZZLING";
	PriceDesc pd59;
	pd59.price = 13.95;
	pd59.desc = "Combination seafood cooked with garlic chili, bell peppers, and basil.";
	pair<string, PriceDesc> p59(n59, pd59);
	menu.insert(p59);
	pair<string, double> pair59(n59, pd59.price);
	vs.push_back(pair59);

	string n60 = "GINGER FISH";
	PriceDesc pd60;
	pd60.price = 13.95;
	pd60.desc = "Stir-fried fish fillet in yellow bean sauce with ginger.";
	pair<string, PriceDesc> p60(n60, pd60);
	menu.insert(p60);
	pair<string, double> pair60(n60, pd60.price);
	vs.push_back(pair60);

	//Sort Vector Food Menu
	sort(vs.begin(), vs.end());

	//Create Dessert Menu
	map<string, double> des;

	//Fill in Dessert Menu
	des.insert( pair<string, double>("Sweet Sticky Rice with Mango", 5.95) );
	des.insert( pair<string, double>("Sweet Sticky Rice with Custard", 5.95) );
	des.insert( pair<string, double>("Fried Banana with Ice Cream", 5.95) );
	des.insert( pair<string, double>("Sweet Sticky Rice with Mango", 5.95) );
	des.insert( pair<string, double>("Coconut Ice Cream", 3.95) );
	des.insert( pair<string, double>("Ice Cream Sundae", 3.95) );
	des.insert( pair<string, double>("Lychee Nuts", 2.95) );
	des.insert( pair<string, double>("Thai Fruits in Syrup over Ice", 2.95) );

	//Loop until Finished Order
	while(1)
	{
		//Print Main Menu
		mainMenu();

		//Get Choice
		char choice;
		cout << "Please enter the number of your choice: ";
		cin >> choice;
		cout << endl;

		//Print Menu With Desc
		if (choice == '1')
		{
			printMenu(menu);
		}
		//Print Ref Menu and Order
		else if (choice == '2')
		{
			//Stack of Order List
			stack<string> orderl;
			orderl.push("Dessert");
			orderl.push("Food");
			orderl.push("Drink");

			//Queue of Order
			queue<string> order;

			//Set of Price
			multiset<double> priceSet;

			char c;
			while (!orderl.empty())
			{
				//Order Drink
				if (orderl.top() == "Drink")
				{
					//Print Drink Menu
					printDrink(drink);

					//Order
					orderDrink(drink, order, priceSet);

					//Print Current Order
					cout << endl;
					cout << "Current Order: " << endl;
					printOrder(order);

					//Print Subtotal
					cout << "Subtotal: " << total(priceSet) << endl << endl;

					//Confirmation
					cout << "Proceed? (y/n): ";
					cin >> c;
					cout << endl;

					//Next Step
					if (c == 'Y' || c == 'y')
					{
						orderl.pop();
					}
					//Restart
					else
					{
						removeOrder(order);
						removeTotal(priceSet);
					}

				}
				//Order Food
				else if (orderl.top() == "Food")
				{
					//Print Food Menu
					printQuickMenu(vs);

					//Order
					orderMenu(vs, order, priceSet);

					//Print Current Order
					cout << endl;
					cout << "Current Order: " << endl;
					printOrder(order);

					//Print Subtotal
					cout << "Subtotal: " << total(priceSet) << endl << endl;

					//Confirmation
					cout << "Proceed? (y/n): ";
					cin >> c;
					cout << endl;

					//Next Step
					if (c == 'Y' || c == 'y')
					{
						orderl.pop();
					}
					//Restart
					else
					{
						removeOrder(order);
						removeTotal(priceSet);
						orderl.push("Drink");
					}
				}
				//Order Dessert
				else
				{
					//Print Dessert Menu
					printDessert(des);

					//Order
					orderDessert(des, order, priceSet);

					//Print Current Order
					cout << endl;
					cout << "Current Order: " << endl;
					printOrder(order);

					//Print Subtotal
					cout << "Subtotal: " << total(priceSet) << endl << endl;

					//Confirmation
					cout << "Proceed? (y/n): ";
					cin >> c;
					cout << endl;

					//Next Step
					if (c == 'Y' || c == 'y')
					{
						orderl.pop();
					}
					//Restart
					else
					{
						removeOrder(order);
						removeTotal(priceSet);
						orderl.push("Food");
						orderl.push("Drink");
					}
				}
			}

			//Print Final
			cout << endl;
			cout << "Final Order: " << endl;
			printOrder(order);

			cout << "Subtotal: " << total(priceSet) << endl << endl;

			cout << "Tax: 8.75%" << endl;

			//Print Total with Tax
			cout << "Total: " << setprecision(2) << fixed << total(priceSet) * 1.0875 << endl << endl;
			
			cout << "Thank you for your order" << endl << endl;

			return 0;
		}
		//Check Validity
		else
		{
			cout << "Invalid input." << endl << endl;
		}
	}
}

//Show Main Menu
void mainMenu()
{
	cout << "* * * * * * * MAIN MENU * * * * * * *" << endl;
	cout << "* 1. Display Menu with Description  *" << endl;
	cout << "* 2. Ready to Order                 *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * *" << endl;
}

//Show Drink Menu
void printDrink(map<string, double> &drink)
{
	cout << "* * * * * DRINKS * * * * *" << endl;
	unsigned i = 1;
	for (map<string, double>::iterator it = drink.begin();
		it != drink.end();
		++it)
	{
		if (i < 10)
		{
			cout << "0";
		}
	
		cout << i << ". ";
		cout << left << setw(18) << it->first << it->second << endl;
		++i;
	}
	cout << endl;
}

//Process Drink Order
void orderDrink(map<string, double> &drink, queue<string> &order, multiset<double> &price)
{
	int d;

	do
	{
		//Get User Order
		cout << "Please enter the drink number you wish to order (-1 when finish): ";
		cin >> d;

		if (d == -1) return;

		//Check Validity
		if (d >= 1 && d <= (int) drink.size())
		{
			map<string, double>::iterator it = drink.begin();

			for (int i = 2; i <= d; ++i)
			{
				++it;
			}

			order.push(it->first);
			price.insert(it->second);
		}
		else
		{
			cout << "Invalid choice.";
		}
	} while (1);
}

//Show Quick Food Menu 
void printQuickMenu(vector< pair<string, double> > &vs)
{
	cout << "* * * * * * * * * * FOOD * * * * * * * * * *" << endl;
	for (unsigned i = 1; i <= vs.size(); ++i)
	{
		if (i < 10)
		{
			cout << "0";
		}

		cout << i << ". ";
		cout << left << setw(35) << vs.at(i-1).first << vs.at(i-1).second << endl;
	}
	cout << endl;
}

//Show Food Menu with description
void printMenu(map<string, PriceDesc> &menu)
{
	cout << "* * * * * FOOD * * * * *" << endl;
	unsigned i = 1;
	for (map<string, PriceDesc>::iterator it = menu.begin();
		it != menu.end();
		++it)
	{
		if (i < 10)
		{
			cout << "0";
		}

		cout << i << ". ";
		cout << left << setw(20) << it->first << " ";
		cout << it->second.price << endl;
		cout << it->second.desc << endl << endl;
		++i;
	}
}

//Process Food Order
void orderMenu(vector< pair<string, double> > &vs, queue<string> &order, multiset<double> &price)
{
	int d;

	do
	{
		cout << "Please enter the food number you wish to order (-1 when finish): ";
		cin >> d;

		if (d == -1) return;

		if (d >= 1 && d <= (int) vs.size())
		{
			order.push(vs.at(d-1).first);
			price.insert(vs.at(d-1).second);
		}
		else
		{
			cout << "Invalid choice.";
		}
	} while (1);
}

//Show Dessert Menu
void printDessert(map<string, double> &des)
{
	cout << "* * * * * * * * * * DESSERT * * * * * * * * * *" << endl;
	unsigned i = 1;
	for (map<string, double>::iterator it = des.begin();
		it != des.end();
		++it)
	{
		if (i < 10)
		{
			cout << "0";
		}
	
		cout << i << ". ";
		cout << left << setw(35) << it->first << it->second << endl;
		++i;
	}
	cout << endl;
}

//Process Dessert Order
void orderDessert(map<string, double> &des, queue<string> &order, multiset<double> &price)
{
	int d;

	do
	{
		cout << "Please enter the dessert number you wish to order (-1 when finish): ";
		cin >> d;

		if (d == -1) return;

		if (d >= 1 && d <= (int) des.size())
		{
			map<string, double>::iterator it = des.begin();

			for (int i = 2; i <= d; ++i)
			{
				++it;
			}

			order.push(it->first);
			price.insert(it->second);
		}
		else
		{
			cout << "Invalid choice.";
		}
	} while (1);
}

//Print Order
void printOrder(queue<string> order)
{
	while (!order.empty())
	{
		cout << order.front() << endl;
		order.pop();
	}

	cout << endl;
}

//Calculate Total
double total(multiset<double> &price)
{
	double d = 0;

	for (multiset<double>::iterator it = price.begin();
		it != price.end();
		++it)
	{
		d += *it;
	}

	return d;
}

//Delete Order
void removeOrder(queue<string> &order)
{
	while (!order.empty())
	{
		order.pop();
	}
}

//Delete Subtotal
void removeTotal(multiset<double> &price)
{
	price.clear();
}
