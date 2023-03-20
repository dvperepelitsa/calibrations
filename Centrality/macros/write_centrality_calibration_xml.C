#include <PHParameters.h>

// run interactively with:
//    .L $OFFLINE_MAIN/lib/libphparameter.so
//    .x write_centrality_calibration_xml.C

void write_centrality_calibration_xml() {

  PHParameters* param = new PHParameters("centrality");

  param->set_string_param("description","Centrality calibration from MDC-2, March 2023 workfest");

  std::string line;
  std::ifstream myfile ("centrality_input_simple.txt");
  if (myfile.is_open())
    {
      int cent;

      // sEPD Reconstructed tiles
      cent = 0;
      getline (myfile,line); // dummy line for human readibility
      for (int n = 0; n < 11; n++) {
	getline (myfile,line);
	float centile_value = atof(line.c_str());
	std::cout << " sEPD Tiles, centile " << cent << ", value = " << centile_value << std::endl;

	std::ostringstream s;
	s << "epd_centile_" << cent;
	param->set_double_param( s.str().c_str() , centile_value );

	cent += 10;
      }

      // MVTX cluster multiplicity
      cent = 0;
      getline (myfile,line); // dummy line for human readibility
      for (int n = 0; n < 11; n++) {
	getline (myfile,line);
	float centile_value = atof(line.c_str());
	std::cout << " MVTX N_cluster, centile " << cent << ", value = " << centile_value << std::endl;

	std::ostringstream s;
	s << "mvtx_centile_" << cent;
	param->set_double_param( s.str().c_str() , centile_value );

	cent += 10;
      }

      // sEPD G4Hit Sum (legacy)
      cent = 0;
      getline (myfile,line); // dummy line for human readibility
      for (int n = 0; n < 11; n++) {
	getline (myfile,line);
	float centile_value = atof(line.c_str());
	std::cout << " sEPD G4Hit Sum (legacy), centile " << cent << ", value = " << centile_value << std::endl;

	std::ostringstream s;
	s << "epd_g4hit_centile_" << cent;
	param->set_double_param( s.str().c_str() , centile_value );

	cent += 10;
      }

      // MBD G4Hit Sum (legacy) 
      cent = 0;
      getline (myfile,line); // dummy line for human readibility
      for (int n = 0; n < 11; n++) {
	getline (myfile,line);
	float centile_value = atof(line.c_str());
	std::cout << " MBD G4Hit Sum (legacy), centile " << cent << ", value = " << centile_value << std::endl;

	std::ostringstream s;
	s << "mbd_g4hit_centile_" << cent;
	param->set_double_param( s.str().c_str() , centile_value );

	cent += 10;
      }

      // b (impact parameter)
      cent = 0;
      getline (myfile,line); // dummy line for human readibility
      for (int n = 0; n < 11; n++) {
	getline (myfile,line);
	float centile_value = atof(line.c_str());
	std::cout << " b, centile " << cent << ", value = " << centile_value << std::endl;

	std::ostringstream s;
	s << "bimp_centile_" << cent;
	param->set_double_param( s.str().c_str() , centile_value );

	cent += 10;
      }

      myfile.close();
    }

  else {
    std::cout << "Unable to open calibration file" << std::endl;
  } 

  param->WriteToFile("xml", "..");

}
