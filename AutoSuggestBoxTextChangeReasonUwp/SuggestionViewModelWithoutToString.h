#pragma once

#include "SuggestionViewModelWithoutToString.g.h"

namespace winrt::AutoSuggestBoxTextChangeReasonUwp::implementation
{
    struct SuggestionViewModelWithoutToString : SuggestionViewModelWithoutToStringT<SuggestionViewModelWithoutToString>
    {

        SuggestionViewModelWithoutToString(hstring displayName) : mDisplayName(displayName) {}
        hstring DisplayName() const { return mDisplayName; }
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value)
        {
            return mPropertyChanged.add(value);
        }
        void PropertyChanged(winrt::event_token const& token)
        {
            mPropertyChanged.remove(token);
        }
    private:
        hstring mDisplayName;
        winrt::event<winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler> mPropertyChanged;
    };
}

namespace winrt::AutoSuggestBoxTextChangeReasonUwp::factory_implementation
{
    struct SuggestionViewModelWithoutToString : SuggestionViewModelWithoutToStringT<SuggestionViewModelWithoutToString, implementation::SuggestionViewModelWithoutToString>
    {
    };
}
