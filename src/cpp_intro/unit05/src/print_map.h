template<typename M>
void print_map(M& m) {
   cout << '{'; auto i=begin(m);
   for (auto j=--end(m); i != j; i++)
        cout << i->first << ':'
             << i->second << ',';
   cout << i->first << ':' << i->second << '}'
        << endl;
}
