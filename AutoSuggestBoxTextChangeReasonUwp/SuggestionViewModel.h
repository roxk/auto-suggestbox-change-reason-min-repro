#pragma once

#include "SuggestionViewModel.g.h"

namespace winrt::AutoSuggestBoxTextChangeReasonUwp::implementation
{
    struct SuggestionViewModel : SuggestionViewModelT<SuggestionViewModel>
    {
        SuggestionViewModel(hstring displayName) : mDisplayName(displayName) {}
        hstring DisplayName() const { return mDisplayName; }
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value)
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
        winrt::event<winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler> mPropertyChanged;
    };
}

namespace winrt::AutoSuggestBoxTextChangeReasonUwp::factory_implementation
{
    struct SuggestionViewModel : SuggestionViewModelT<SuggestionViewModel, implementation::SuggestionViewModel>
    {
    };
}
