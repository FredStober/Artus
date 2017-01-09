
#pragma once

template < class TEvent, class TProduct, class TSettings >
class SourceBase
{
public:
	virtual bool GetValue(TEvent const& event,
			TProduct const& product,
			TSettings const& settings,
			double & val) const = 0 ;


	virtual void StartOnEvent(TEvent const& event,
			TProduct const& product,
			TSettings const& settings) const {}


	virtual void EndOnEvent(TEvent const& event,
			TProduct const& product,
			TSettings const& settings) const {}


	virtual bool HasDefaultBinCount() const
	{
		return true;
	}

	virtual double HasDefaultBins() const
	{
		return true;
	}


	virtual unsigned int GetDefaultBinCount() const
	{
		LOG(FATAL) << "Implement this for your class!";
	}

	virtual double GetDefaultLowBin() const
	{
		LOG(FATAL) << "Implement this for your class!";
	}

	virtual double GetDefaultHighBin() const
	{
		LOG(FATAL) << "Implement this for your class!";
	}
};
