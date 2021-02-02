#ifndef __SEQDNA_H__
#define __SEQDNA_H__

#include "IdnaSeq.h"
#include <cstring>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <tgmath.h>

using std::string;


class DnaSequence: public IDnaSequence{
public:
    class Nucleotide{

    public:
        Nucleotide(){}
        
        Nucleotide(char val);
        
        bool isValid(const char) const;
        
        Nucleotide & operator=(const char);
        
        operator char() const;
        
    private:
        char m_nuc;
    };
    

    DnaSequence(char *seq);
    
    DnaSequence(string seq);
    
    DnaSequence(const DnaSequence & seq1);
    
    ~DnaSequence();
    
    const std::string getSeq() const;

    const size_t getLength() const;
    
    char pair(char); 
    
    Nucleotide * pairing();

    DnaSequence & slice(size_t start , size_t end);

    const size_t findSubSeq(const DnaSequence & subSeq, size_t index) const;
    
    const std::vector<size_t> findallsubSeq(const DnaSequence & subSeq) const;
    
    size_t count(const DnaSequence & subSeq);
    
    std::vector<size_t> & findConsensusSequences();
    
    DnaSequence & operator= (const DnaSequence & seq1);
    
    Nucleotide & operator[] (size_t index);
    
    const Nucleotide & operator[] (size_t index) const;

    friend std::ostream& operator<<(std::ostream& os, const DnaSequence& sequence);

private:
    Nucleotide * m_seq;
    size_t m_length;

};

/************Nucleotide functions*****************/

inline DnaSequence::Nucleotide::Nucleotide(char val)
{
    
    if (isValid(val))
        m_nuc = val;

    else throw std::invalid_argument("Invalid argument");
}

//TODO should work also for lower case
inline bool DnaSequence::Nucleotide::isValid(const char i) const
{
        return (i == 'A' || i == 'T' || i == 'G' || i == 'C');
}

inline DnaSequence::Nucleotide & DnaSequence::Nucleotide::operator=(const char val)
{
    if (isValid(val))
    {
        m_nuc = val;
    }

    else
    {
        throw std::invalid_argument("Invalid argument");
    }

    return *this;
}

inline DnaSequence::Nucleotide::operator char() const
{
    return m_nuc;
}

/************DnaSequence functions*****************/

/*char* constructor*/
inline DnaSequence::DnaSequence(char * seq) : m_seq(NULL) , m_length(strlen(seq)){

    if (seq == NULL)
        throw std::invalid_argument("invalid argument");

    m_seq = new Nucleotide[m_length + 1];
    try
    {
        for (size_t i = 0; i < m_length ; i++)
            m_seq[i] = seq[i];
    }
    catch (std::invalid_argument) {
        delete [] m_seq;
        throw;
    }

}

/*string constructor*/
inline DnaSequence::DnaSequence(const string seq) : m_seq(NULL) , m_length(seq.length()){
    
    if (seq == "")
        throw std::invalid_argument("invalid argument");

    m_seq = new Nucleotide[m_length + 1];
    try{
        
        for (size_t i = 0; i < m_length ; i++)
            m_seq[i] = seq[i];
    }
    catch (std::invalid_argument) {
        delete [] m_seq;
        throw;
    }
}

/*copy constructor*/
inline DnaSequence::DnaSequence(const DnaSequence& seq1) : m_length(seq1.getLength())
{
    m_seq = new Nucleotide[m_length];

    for (size_t i = 0 ; i < m_length ; i++)
        m_seq[i] = seq1.m_seq[i];

}

/*destructor*/
inline DnaSequence::~DnaSequence()
{
    delete [] m_seq;
}

/*getSeq*/
inline const std::string DnaSequence::getSeq() const
{
    std::string _ = "";
    for (size_t i = 0; i < m_length; i++)
    {
        _ += m_seq[i];
    }
    return _;
}

/*getlength*/
inline const size_t DnaSequence::getLength() const
{
    return m_length;
}

/*slice*/
inline DnaSequence & DnaSequence::slice(size_t start , size_t end)
{
    string myString = "";

    for (size_t i = start ; i < end ; i++)
    {
        string s(1, m_seq[i]);
		myString += s;
	}
    DnaSequence subdna(myString);

    return subdna;
}

/*pairing*/
inline DnaSequence::Nucleotide * DnaSequence::pairing()
{
	
	size_t len = getLength();

	for (size_t i = 0; i < len / 2; i++)
	{
		std::swap(m_seq[i], m_seq[len - i - 1]);
		m_seq[i] = pair(m_seq[i]);
		m_seq[len - i -1] = pair(m_seq[len - i - 1]);
	}
	if(len % 2 == 1)
    {
	    m_seq[len / 2] = pair(m_seq[len / 2]);
    }

	return m_seq;
}

/*findSubSeq*/
inline const size_t DnaSequence::findSubSeq(const DnaSequence & subSeq, size_t index = 0) const
{
	
	size_t j = 0, len = subSeq.m_length;
	
	for (size_t i = index; i < m_length - len  ; i++)
	{
        if (m_seq[i] == m_seq[0])
        {
            for (j = 0; j < len; j++)
            {
                if (m_seq[i + j] != subSeq[j])
                {
                    break;
                }
            }
        }
        if (j == len)
        {
            return i;
        }
	}
	return -1;
}

/*findAllsubSeq*/
inline const std::vector<size_t> DnaSequence::findallsubSeq(const DnaSequence & subSeq) const
{
	std::vector<size_t> allsebseq;
	size_t j = 0, len = subSeq.m_length;
	for (size_t i = 0; i < m_length - len  ; i++)
	{
		if (m_seq[i] == m_seq[0])
		{
			for (j = 0; j < subSeq.m_length; j++)
			{	
				if (m_seq[i + j] != subSeq[j])
					break;
			}

			if (j == subSeq.m_length)
            {
                allsebseq.push_back(i);
            }
		}
	}
	return allsebseq;
}

/*count*/
inline size_t DnaSequence::count(const DnaSequence & subSeq)
{
	return findallsubSeq(subSeq).size();
}

/*findConsensusSequences*/
inline std::vector<size_t> & DnaSequence::findConsensusSequences(){
		DnaSequence atg("ATG");
		std::vector<size_t> start = findallsubSeq(atg);
		std::vector<size_t> sub;
		
		for (std::vector<size_t>::iterator it = start.begin(); it != start.end(); ++it) 
		{
            if (findSubSeq("TAG", *it +3) != -1 || findSubSeq("TAA", *it +3) != -1|| findSubSeq("TAA", *it +3) != -1)
            {
                sub.push_back(*it);
            }
				
		}
		
		return sub;
}

inline DnaSequence &  DnaSequence::operator= (const DnaSequence & seq1)
{
    
    if (this != &seq1)
    {
    	Nucleotide *temp = m_seq;
    	m_seq = new Nucleotide[seq1.getLength()];
		delete [] temp;
		m_length = seq1.getLength();
        
        for (size_t i = 0 ; i < m_length ; i++)
        {
            m_seq[i] = seq1.m_seq[i];
        }
	}
	    
    return *this;
}


inline DnaSequence::Nucleotide & DnaSequence::operator[] (size_t index)
{
    return m_seq[index];
}

inline const DnaSequence::Nucleotide & DnaSequence::operator[] (size_t index) const
{
    return m_seq[index];
}

inline std::ostream& operator<<(std::ostream& os, const DnaSequence& sequence)
{
    for (size_t i = 0 ; i < sequence.getLength() ; i++)
    {
        os << sequence.m_seq[i];

    }

    os << std::endl;

    return os << std::endl;
}

inline bool operator== (DnaSequence & seq1, DnaSequence & seq2 ){
    
    if (seq1.getLength() != seq2.getLength())
    {
        return false;
    }

    for (size_t i = 0 ; i < seq1.getLength() ; i++)
    {
        
        if (seq1.getSeq()[i] != seq2.getSeq()[i])
        {
            return false;
        }

    }

    return true;
}

inline bool operator!= (DnaSequence & seq1, DnaSequence & seq2)
{
    return !(seq1 == seq2);
}

#endif

