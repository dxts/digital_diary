void menu()
	{
	border('*',1,1,80,24);
	gotoxy(33,3);
	cout<<"DIGITAL DIARY";
	
    gotoxy(27,6);
	cout<<"Select the desired option:"<<endl;
	
    border('.',15,8,20,5);
	gotoxy(19,10);
	cout<<"1. Contacts";
	
    border('.',45,8,20,5);
	gotoxy(49,10);
	cout<<"2. World Clock";
	
    border('.',15,16,20,5);
	gotoxy(17,17);
	cout<<"3. Calculator";
	gotoxy(24,18);
	cout<<"and";
	gotoxy(25,19);
	cout<<"converter";
	
    border('.',45,16,20,5);
	gotoxy(48,17);
	cout<<"4. Notes";
	gotoxy(53,18);
	cout<<"and";
	gotoxy(52,19);
	cout<<"To-Do list";
	
    gotoxy(39,22);
	cout<<"__";
}
