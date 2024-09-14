#pragma once

#include "../../DocxFormat/WritingElement.h"
#include "../../Base/Nullable.h"

#include "../../Common/ComplexTypes.h"


namespace OOX
{
	namespace Logic
	{
        class CRuby;
        class CRun;

        class CRubyProperty : public WritingElement 
        {
        public:
            CRubyProperty();
            ~CRubyProperty();

            CRubyProperty(const XmlUtils::CXmlNode& oNode);
            CRubyProperty(const XmlUtils::CXmlLiteReader& oReader);

            const CRubyProperty& operator =(const XmlUtils::CXmlNode& oNode);
            const CRubyProperty& operator =(const XmlUtils::CXmlLiteReader& oReader);

            bool IsNoEmpty();
            void Clear();

            virtual void fromXML(XmlUtils::CXmlNode& oNode);
            virtual void fromXML(XmlUtils::CXmlLiteReader& oReader);
            
            virtual std::wstring toXML() const;
            virtual void toXmlWriter(NSBinPptxRW::CXmlWriter* pWriter) const;
            virtual EElementType getType() const;

            template <typename Type>
            static nullable<Type> Merge(const nullable<Type>& oPrev, const nullable<Type>& oCurrent)
            {
                nullable<Type> oResult;

                if (oCurrent.IsInit())
                    oResult = oCurrent;
                else if (oPrev.IsInit())
                    oResult = oPrev;

                return oResult;
            }

            static const CRubyProperty Merge(const CRubyProperty& oPrev, const CRubyProperty& oCurrent);

            
            nullable<ComplexTypes::Word::CRubyAlign>  m_oRubyAlign;
            nullable<ComplexTypes::Word::CHpsMeasure> m_oHps;
            nullable<ComplexTypes::Word::CHpsMeasure> m_oHpsRaise;
            nullable<ComplexTypes::Word::CHpsMeasure> m_oHpsBaseText;
            nullable<ComplexTypes::Word::CLang>       m_oLid;
        };

        //--------------------------------------------------------------------------------
		// CRuby 17.3.3.25 (Part 1)
		//--------------------------------------------------------------------------------	
		class CRuby : public WritingElement
		{
		public:
			WritingElement_AdditionMethods(CRuby)
			CRuby(OOX::Document *pMain = NULL);
			virtual ~CRuby();

		public:
			virtual void         fromXML(XmlUtils::CXmlNode& oNode);
			virtual void         fromXML(XmlUtils::CXmlLiteReader& oReader);

			nullable<CRun> m_oRubyBase;
			nullable<CRun> m_oRubyText;
			nullable<CRubyProperty> m_oRubyPr;

			virtual std::wstring      toXML() const;
			virtual EElementType getType() const;
		};


    } // namespace Logic
} // namespace OOX