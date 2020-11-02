#pragma once

#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "SuggestionViewModelWithoutToString.g.h"

namespace winrt::AutoSuggestBoxTextChangeReasonMinRepro::implementation
{
    struct SuggestionViewModelWithoutToString : SuggestionViewModelWithoutToStringT<SuggestionViewModelWithoutToString>
    {
        SuggestionViewModelWithoutToString(hstring displayName) : mDisplayName(displayName) {}
        hstring DisplayName() const { return mDisplayName; }
        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& value)
        {
            return mPropertyChanged.add(value);
        }
        void PropertyChanged(winrt::event_token const& token)
        {
            mPropertyChanged.remove(token);
        }
    private:
        hstring mDisplayName;
        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> mPropertyChanged;
    };
}

namespace winrt::AutoSuggestBoxTextChangeReasonMinRepro::factory_implementation
{
    struct SuggestionViewModelWithoutToString : SuggestionViewModelWithoutToStringT<SuggestionViewModelWithoutToString, implementation::SuggestionViewModelWithoutToString>
    {
    };
}
