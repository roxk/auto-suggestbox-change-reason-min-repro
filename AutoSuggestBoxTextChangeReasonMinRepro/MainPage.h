#pragma once

#include "SuggestionViewModel.h"
#include "SuggestionViewModelWithoutToString.h"
#include "MainPage.g.h"

namespace winrt::AutoSuggestBoxTextChangeReasonMinRepro::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();
        Windows::Foundation::Collections::IObservableVector<IInspectable> Suggestions() { return mSuggestions; }
        Windows::Foundation::Collections::IObservableVector<IInspectable> SuggestionWithoutToStrings() { return mSuggestionWithoutToStrings; }
        void AutoSuggestBox_TextChanged(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs const& args);
        void AutoSuggestBox_SuggestionChosen(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs const& args);
        void AutoSuggestBox_QuerySubmitted(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs const& args);
        void AutoSuggestBox_TextChanged_Without_ToString(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs const& args);
        void AutoSuggestBox_SuggestionChosen_Without_ToString(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs const& args);
        void AutoSuggestBox_QuerySubmitted_Without_ToString(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs const& args);
    private:
        Windows::Foundation::Collections::IObservableVector<IInspectable> mSuggestions;
        Windows::Foundation::Collections::IObservableVector<IInspectable> mSuggestionWithoutToStrings;
        Windows::Foundation::IAsyncAction UpdateSuggestions(hstring query);
        Windows::Foundation::IAsyncAction UpdateSuggestionWithoutToStrings(hstring query);
    };
}

namespace winrt::AutoSuggestBoxTextChangeReasonMinRepro::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
