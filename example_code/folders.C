void folders()
{
	TFolder* aliroot = gROOT->GetRootFolder()->AddFolder("aliroot", "aliroot top level folders");
	gROOT->GetListOfBrowsables()->Add(aliroot, "aliroot");

	TFolder* constants = aliroot->AddFolder("Constants", "Detector constants");

	TFolder* pdg = constants->AddFolder("DatabasePDG", "PDG Database");

	TFolder* run = aliroot->AddFolder("Run", "Run dependent folder");

	TFolder* configuration  = run->AddFolder("Configuration", "Run configuration");

	TFolder* run_mc = aliroot->AddFolder("RunMC", "MonteCarlo run dependents folders");

	TFolder* configuration_mc = run_mc->AddFolder("Configuration", "MonteCarlo run configuration");
}