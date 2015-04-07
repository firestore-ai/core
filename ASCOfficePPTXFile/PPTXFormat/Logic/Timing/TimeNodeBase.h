#pragma once
#ifndef PPTX_LOGIC_TIMENODEBASE_INCLUDE_H_
#define PPTX_LOGIC_TIMENODEBASE_INCLUDE_H_

#include "./../../WrapperWritingElement.h"

namespace PPTX
{
	namespace Logic
	{
		class TimeNodeBase : public WrapperWritingElement
		{
		public:
			TimeNodeBase();
			virtual ~TimeNodeBase();
			explicit TimeNodeBase(XmlUtils::CXmlNode& node);
			const TimeNodeBase& operator =(XmlUtils::CXmlNode& node);

		public:
			virtual void fromXML(XmlUtils::CXmlNode& node);
			virtual void GetTimeNodeFrom(XmlUtils::CXmlNode& element);
			virtual bool is_init()const{return (m_node.IsInit());};
			
			//template<class T> const bool is() const { return (!m_node.IsInit())?false:(typeid(*m_node) == typeid(T));}
			//template<class T> T& as() {return static_cast<T&>(*m_node);}
			//template<class T> const T& as() const {return static_cast<const T&>(*m_node);}
			
			template<class T> AVSINLINE const bool	is() const	{ return m_node.is<T>(); }
			template<class T> AVSINLINE T&			as()		{ return m_node.as<T>(); }
			template<class T> AVSINLINE const T&	as() const 	{ return m_node.as<T>(); }

			virtual CString toXML() const;
		//public:
		private:
			smart_ptr<WrapperWritingElement> m_node;
		protected:
			virtual void FillParentPointersForChilds(){};
		public:
			virtual void SetParentPointer(const WrapperWritingElement* pParent)
			{
				if(is_init())
					m_node->SetParentPointer(pParent);
			}
		};
	} // namespace Logic
} // namespace PPTX

#endif // PPTX_LOGIC_TIMENODEBASE_INCLUDE_H_