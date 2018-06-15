void tree1()
{
	TFile f("tree1.root", "recreate"); // создаем файл
	TTree t1("t1", "Simple Tree"); // Создаем древо
	Float_t px, py, pz;
	Int_t ev;
	t1.Branch("px", &px, "Px/F"); // Создаем три ветви
	t1.Branch("py", &py, "Py/F"); // содержащие значения Float_t
	t1.Branch("pz", &pz, "Pz/F");
	t1.Branch("ev", &ev, "ev/I"); // и одну со значением Int_t

	for(Int_t i = 0; i < 10000; i++)
	{
		gRandom->Rannor(px, py);
		pz = px*px + py*py;
		ev = i;
		t1.Fill(); // По команде Fill() значение переменных заносятся в дерево
	}

	t1.Write(); // Записываем дерево в файл
	t1.Print(); // Выводим общую информацию о дереве

	for(Int_t i = 57; i < 100; i++)
	{
		t1.Show(i); // Выводим все значения, записанные в i-м вхождении (событии)
		cout << '\n';
	}
}
