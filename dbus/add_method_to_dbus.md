- Add in `Interface_DBUS/parameters.xml`
- depuis interface_dbus, utiliser `generate_qdbus_code.sh`
- merger les nouveaux fichiers (genre avec meld) avec les existants (dans api_proxy.hpp ça en crée 2 c'est normal, dans api_adaptor.cpp, remplir la méthode)
- créer la vraie méthode dans ProcessingDbusHandler


invalid: List of not imported parameters due to wrong values
unknown: List of unknown parameters
/home/alstom/Dev/neyrpic-tru/Exclusif/Documentation/Documentation\ technique/test_files/parameters_1.xml
`busctl call --user com.neyrpic.tru_v1.processing /com/neyrpic/tru_v1/processing com.neyrpic.tru_v1.processing parameters_load s "/home/alstom/Dev/neyrpic-tru/Exclusif/Documentation/Documentation\ technique/test_files/parameters_1.xml"`