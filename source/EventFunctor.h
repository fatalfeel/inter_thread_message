#ifndef EVENT_FUNCTOR_H
#define EVENT_FUNCTOR_H

template<class ParamInfo> 
class EventFunctorBase
{
public:
    virtual ~EventFunctorBase(){}
	virtual void*	getThis()				        = 0;
	virtual void	callMember(ParamInfo* event)    = 0;
};

template<class ClassName, class ParamInfo> 
class EventFunctor : public EventFunctorBase<ParamInfo>
{
public:
	typedef void (ClassName::*ClassMember)(ParamInfo*); //ParamInfo is func's paramater

	EventFunctor(ClassName* classptr, ClassMember member)
	{
		m_pThis		= classptr;
		m_pMember   = member;
	}

	virtual ~EventFunctor(){}

	virtual void* getThis() 
	{ 
		return m_pThis; 
	}
	
	virtual void callMember(ParamInfo* event)
	{ 
		if(m_pThis)
			(m_pThis->*m_pMember)(event);
	}

private:
	ClassName*	m_pThis;
	ClassMember	m_pMember;
};

#endif // I_FUNCTOR_H
