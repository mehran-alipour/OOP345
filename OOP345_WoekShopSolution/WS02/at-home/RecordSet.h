// RecordSet.h
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Jan 24,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RECORDSET_H__
#define SDDS_RECORDSET_H__
#include <string>
namespace sdds {
    class RecordSet {
        unsigned int r_numRecSet{0};
        std::string* r_arr;
    public:
        RecordSet();
        RecordSet(const RecordSet& copyCon);
        RecordSet(RecordSet&& );
        RecordSet(const char* fileName);
        size_t size()const;
        std::string getRecord(size_t);
        RecordSet& operator=(const RecordSet& copyOp);
        RecordSet& operator=(RecordSet&& moveOp);
        virtual ~RecordSet();
    };
}
#endif // End of Safegard