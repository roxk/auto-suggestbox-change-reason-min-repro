#pragma once

#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "SuggestionViewModel.g.h"

namespace winrt::AutoSuggestBoxTextChangeReasonMinRepro::implementation
{
    struct SuggestionViewModel : SuggestionViewModelT<SuggestionViewModel>
    {
        SuggestionViewModel(hstring displayName) : mDisplayName(displayName) {}
        hstring DisplayName() const { return mDisplayName; }
        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& value)
        {
            return mPropertyChanged.add(value);
        }
        void PropertyChanged(winrt::event_token const& token)
        {
            mPropertyChanged.remove(token);
        }
        hstring ToString() const {
            return mDisplayName;
        }
    private:
        hstring mDisplayName;
        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> mPropertyChanged;
    };
}

namespace winrt::AutoSuggestBoxTextChangeReasonMinRepro::factory_implementation
{
    struct SuggestionViewModel : SuggestionViewModelT<SuggestionViewModel, implementation::SuggestionViewModel>
    {
    };
}
